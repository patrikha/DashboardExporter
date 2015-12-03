# DashboardExporter

Command line utility for exporting dashboard charts from [Hansoft](http://hansoft.com) to json or png files. For a simple setup have a look at the [Hansoft docker](https://hub.docker.com/r/patrikha/hansoftserver/).

## Build
Download [HansoftSDK](http://www.hansoft.com/en/support/downloads) and unzip the content to the HansoftSDK folder.

## Usage
For help please use the build-in help command: DashboardExporter --help
```
Usage: DashboardExporter [options]

Hansoft Dashboard exporter

Options:
  -h, --help            show this help message and exit
  -s SERVER, --server=SERVER
                        Hansoft server address
  -p PORT, --port=PORT  Hansoft server port
  -d DATABASE, --database=DATABASE
                        Hansoft database
  -u USERNAME, --username=USERNAME
                        Hansoft SDK username
  -p PASSWORD, --password=PASSWORD
                        Hansoft SDK password
  -r RESOURCE, --resource=RESOURCE
                        Hansoft dasboard owner username
  -c CHART, --chart=CHART
                        Hansoft chart id(s), use comma separated list for
                        multiple ids.
  -x RESOLUTION, --resolution=RESOLUTION
                        Image resolution <width> <height> <quality>
  -j, --json            Export data as JSON instead of image
```

## Limitations
Tested on OSX and Linux.

The following folders should be created next to the application:
* IRG
* CHARTS
* JSON
