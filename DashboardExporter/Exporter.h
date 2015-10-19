//
//  Exporter.h
//  DashboardExporter
//
//  Created by Patrik Hartlén on 2015-04-26.
//  Copyright (c) 2015 Patrik Hartlén. All rights reserved.
//  License BSD-style license
//

#ifndef DashboardExporter_Exporter_h
#define DashboardExporter_Exporter_h

using std::string;
using std::vector;

void Export(string server, int port, string database, string username, string password, string resource, vector<int> charts, string resolution, bool json);

#endif
