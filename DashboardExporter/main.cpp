//
//  main.cpp
//  DashboardExporter
//
//  Created by Patrik Hartlén on 2015-04-26.
//  Copyright (c) 2015 Patrik Hartlén. All rights reserved.
//  License BSD-style license
//

#include "OptionParser.h"
#include "Exporter.h"
#include <iostream>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

vector<int> SplitString(string ChartsIDs)
{
    vector<int> vect;
    std::stringstream ss(ChartsIDs);
    int i;

    while (ss >> i)
    {
        vect.push_back(i);
    
        if (ss.peek() == ',' || ss.peek() == ' ')
            ss.ignore();
    }
    return vect;
}

int main(int argc, const char * argv[]) {
    optparse::OptionParser parser = optparse::OptionParser().description("Hansoft Dashboard exporter");
    parser.add_option("-s", "--server").dest("server").help("Hansoft server address").set_default("localhost").metavar("SERVER");
    parser.add_option("-p", "--port").dest("port").help("Hansoft server port").set_default("50256").metavar("PORT");
    parser.add_option("-d", "--database").dest("database").help("Hansoft database").metavar("DATABASE");
    parser.add_option("-u", "--username").dest("username").help("Hansoft SDK username").metavar("USERNAME");
    parser.add_option("-p", "--password").dest("password").help("Hansoft SDK password").metavar("PASSWORD");
    parser.add_option("-r", "--resource").dest("resource").help("Hansoft dasboard owner username").metavar("RESOURCE");
    parser.add_option("-c", "--chart").dest("chart").help("Hansoft chart id(s), use comma separated list for multiple ids.").metavar("CHART");
    parser.add_option("-x", "--resolution").dest("resolution").help("Image resolution <width> <height> <quality>").set_default("800 600 medium").metavar("RESOLUTION");
    parser.add_option("-j", "--json").dest("json").help("Export data as JSON instead of image").metavar("JSON");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();
    
    string server = string(options.get("server"));
    int port = atoi(options.get("port"));
    string database = string(options.get("database"));
    string username = string(options.get("username"));
    string password = string(options.get("password"));
    string resource = string(options.get("resource"));
    vector<int> charts = SplitString(string(options.get("chart")));
    string resolution = string(options.get("resolution"));
    bool json = options.is_set("json");
 
    std::cout << "Exporting dashboard" << std::endl;
    
    Export(server, port, database, username, password, resource, charts, resolution, json);
    
    return 0;
}
