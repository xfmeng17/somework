#include <iostream>
#include <vector>

#include <benchmark/benchmark.h>
#include <boost/algorithm/string.hpp>

using namespace std;

const string s =
    "https://es-h7jpiub2.kibana.tencentelasticsearch.com:5601/app/kibana#/"
    "discover?_g=()&_a=(columns:!(_source),filters:!(('$state':(store:appState)"
    ",meta:(alias:!n,disabled:!f,index:e2420580-b437-11ea-9d17-57bcf81685db,"
    "key:type,negate:!f,params:(query:MISS_FEATURE_INFO,type:phrase),type:"
    "phrase,value:MISS_FEATURE_INFO),query:(match:(type:(query:MISS_FEATURE_"
    "INFO,type:phrase))))),index:e2420580-b437-11ea-9d17-57bcf81685db,interval:"
    "auto,query:(language:lucene,query:''),sort:!('@timestamp',desc))https://"
    "es-h7jpiub2.kibana.tencentelasticsearch.com:5601/app/kibana#/dashboard/"
    "50929f70-0f53-11ea-b747-998ea9e2cdb2?_g=()&_a=(description:'',filters:!(),"
    "fullScreenMode:!f,options:(darkTheme:!f,hidePanelTitles:!f,useMargins:!t),"
    "panels:!((embeddableConfig:(),gridData:(h:31,i:'1',w:48,x:0,y:8),id:'"
    "22510a20-0f53-11ea-b747-998ea9e2cdb2',panelIndex:'1',type:visualization,"
    "version:'6.4.2'),(embeddableConfig:(),gridData:(h:8,i:'2',w:48,x:0,y:0),"
    "id:'08871a10-0f55-11ea-b747-998ea9e2cdb2',panelIndex:'2',type:"
    "visualization,version:'6.4.2')),query:(language:lucene,query:''),"
    "timeRestore:!t,title:%E9%87%87%E6%A0%B7%E7%94%BB%E5%83%8F%E5%88%97%E8%A1%"
    "A8,viewMode:view)https://es-h7jpiub2.kibana.tencentelasticsearch.com:5601/"
    "app/kibana#/dashboard/"
    "a0b4c6f0-1196-11ea-b747-998ea9e2cdb2?_g=()&_a=(description:'',filters:!(),"
    "fullScreenMode:!f,options:(darkTheme:!f,hidePanelTitles:!f,useMargins:!t),"
    "panels:!((embeddableConfig:(),gridData:(h:20,i:'2',w:48,x:0,y:69),id:"
    "e44d9040-1191-11ea-b747-998ea9e2cdb2,panelIndex:'2',title:'local%20cp',"
    "type:visualization,version:'6.4.2'),(embeddableConfig:(),gridData:(h:20,i:"
    "'3',w:48,x:0,y:49),id:'22d10d30-1190-11ea-b747-998ea9e2cdb2',panelIndex:'"
    "3',title:'local%20tag',type:visualization,version:'6.4.2'),("
    "embeddableConfig:(),gridData:(h:9,i:'5',w:48,x:0,y:0),id:'08871a10-0f55-"
    "11ea-b747-998ea9e2cdb2',panelIndex:'5',type:visualization,version:'6.4.2')"
    ",(embeddableConfig:(),gridData:(h:20,i:'6',w:48,x:0,y:9),id:'1fb2b5f0-"
    "89d0-11ea-9d17-57bcf81685db',panelIndex:'6',title:'local%20ca1',type:"
    "visualization,version:'6.8.2'),(embeddableConfig:(),gridData:(h:20,i:'7',"
    "w:48,x:0,y:29),id:'5d2f3840-89d0-11ea-9d17-57bcf81685db',panelIndex:'7',"
    "title:'local%20cat2',type:visualization,version:'6.8.2')),query:(language:"
    "kuery,query:''),timeRestore:!f,title:%E7%94%BB%E5%83%8F%E7%83%AD%E5%9B%BE,"
    "viewMode:view)";

static void sfind_string_split(const string& s, const string& c,
                               vector<string>& res) {
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while (std::string::npos != pos2) {
    res.emplace_back(s.substr(pos1, pos2 - pos1));
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if (pos1 != s.length()) {
    res.emplace_back(s.substr(pos1));
  }
}
static void sfind(benchmark::State& state) {
  for (auto _ : state) {
  vector<string> v1, v2, v3;
  sfind_string_split(s, ":", v1);
  sfind_string_split(s, "8", v2);
  sfind_string_split(s, "(", v3);
  //cerr << "sfind v1.size=" << v1.size() << endl;
  //cerr << "sfind v2.size=" << v2.size() << endl;
  //cerr << "sfind v3.size=" << v3.size() << endl;
  }
}
BENCHMARK(sfind);

static void boost_string_split(const string& s, const string& c,
                               vector<string>& res) {
  boost::split(res, s, boost::is_any_of(c));
}
static void bspit(benchmark::State& state) {
  for (auto _ : state) {
  vector<string> v1, v2, v3;
  boost_string_split(s, ":", v1);
  boost_string_split(s, "8", v2);
  boost_string_split(s, "(", v3);
  //cerr << "bspit v1.size=" << v1.size() << endl;
  //cerr << "bspit v2.size=" << v2.size() << endl;
  //cerr << "bspit v3.size=" << v3.size() << endl;
  }
}
BENCHMARK(bspit);

BENCHMARK_MAIN();
