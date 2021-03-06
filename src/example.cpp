#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "example.h"

// debug
#include <iostream>

bool read_logged_currencies(const std::string& input, Currencies& currencies)
{
    if(input.empty()) { return false; }

        boost::property_tree::ptree pt;
        std::istringstream is(input);

        try {
            boost::property_tree::json_parser::read_json(is, pt);
            currencies.clear();
            for( const auto& rate : pt.get_child("rates") ) {
                 currencies.insert(Currencies::value_type{rate.first, rate.second.get_value<float>()});
            }

        } catch( const boost::property_tree::json_parser::json_parser_error& e) {
            try {
                boost::property_tree::xml_parser::read_xml(is, pt);
                currencies.clear();
				std::string currency;
				float rate;

				for( const auto& elem : pt.get_child("gesmes:Envelope.Cube.Cube") ) {
					if( elem.first == "Cube") {
						for( const auto& i : elem.second.get_child("<xmlattr>") ) {
							if( i.first == "currency" ) { currency = i.second.data(); }
							if( i.first == "rate" ) { rate = std::stod(i.second.data()); }
						}
						if( not currency.empty() ) {
							currencies.insert(Currencies::value_type{currency, rate});
						}
					}
				}

			} catch( const boost::property_tree::xml_parser::xml_parser_error& e) {
                return false;
            }
        }

        return true;
}
