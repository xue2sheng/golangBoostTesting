#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE exampleTest

#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "example.h"

static constexpr char XML_INPUT[] {R"(
<?xml version="1.0" encoding="UTF-8"?>
<gesmes:Envelope xmlns:gesmes="http://www.gesmes.org/xml/2002-08-01" xmlns="http://www.ecb.int/vocabulary/2002-08-01/eurofxref">
        <gesmes:subject>Reference rates</gesmes:subject>
        <gesmes:Sender>
                <gesmes:name>European Central Bank</gesmes:name>
        </gesmes:Sender>
        <Cube>
                <Cube time='2017-09-04'>
                        <Cube currency='USD' rate='1.1905'/>
                        <Cube currency='JPY' rate='130.60'/>
                        <Cube currency='BGN' rate='1.9558'/>
                        <Cube currency='CZK' rate='26.062'/>
                        <Cube currency='DKK' rate='7.4371'/>
                        <Cube currency='GBP' rate='0.91855'/>
                        <Cube currency='HUF' rate='306.02'/>
                        <Cube currency='PLN' rate='4.2406'/>
                        <Cube currency='RON' rate='4.5962'/>
                        <Cube currency='SEK' rate='9.4733'/>
                        <Cube currency='CHF' rate='1.1399'/>
                        <Cube currency='NOK' rate='9.2933'/>
                        <Cube currency='HRK' rate='7.4150'/>
                        <Cube currency='RUB' rate='68.8889'/>
                        <Cube currency='TRY' rate='4.0826'/>
                        <Cube currency='AUD' rate='1.4960'/>
                        <Cube currency='BRL' rate='3.7379'/>
                        <Cube currency='CAD' rate='1.4774'/>
                        <Cube currency='CNY' rate='7.7728'/>
                        <Cube currency='HKD' rate='9.3150'/>
                        <Cube currency='IDR' rate='15869.55'/>
                        <Cube currency='ILS' rate='4.2644'/>
                        <Cube currency='INR' rate='76.2395'/>
                        <Cube currency='KRW' rate='1345.07'/>
                        <Cube currency='MXN' rate='21.2598'/>
                        <Cube currency='MYR' rate='5.0840'/>
                        <Cube currency='NZD' rate='1.6588'/>
                        <Cube currency='PHP' rate='60.953'/>
                        <Cube currency='SGD' rate='1.6150'/>
                        <Cube currency='THB' rate='39.465'/>
                        <Cube currency='ZAR' rate='15.4097'/>
                </Cube>
        </Cube>
</gesmes:Envelope>
)"};

static constexpr char JSON_INPUT[] {R"(
{"base":"EUR","date":"2017-09-04","rates":{"AUD":1.496,"BGN":1.9558,"BRL":3.7379,"CAD":1.4774,"CHF":1.1399,"CNY":7.7728,"CZK":26.062,"DKK":7.4371,"GBP":0.91855,"HKD":9.315,"HRK":7.415,"HUF":306.02,"IDR":15870.0,"ILS":4.2644,"INR":76.24,"JPY":130.6,"KRW":1345.1,"MXN":21.26,"MYR":5.084,"NOK":9.2933,"NZD":1.6588,"PHP":60.953,"PLN":4.2406,"RON":4.5962,"RUB":68.889,"SEK":9.4733,"SGD":1.615,"THB":39.465,"TRY":4.0826,"USD":1.1905,"ZAR":15.41}}
)"};

BOOST_AUTO_TEST_CASE( test000 ) {	
   BOOST_TEST_MESSAGE( "\ntest000: XML" );

   BOOST_CHECK( read_logged_currencies(XML_INPUT) );
}

BOOST_AUTO_TEST_CASE( test001 ) {
   BOOST_TEST_MESSAGE( "\ntest001: JSON" );

   BOOST_CHECK( read_logged_currencies(JSON_INPUT) );
}
