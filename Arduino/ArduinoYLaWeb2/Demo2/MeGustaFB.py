#!/usr/bin/python

import urllib2,json 
data = urllib2.urlopen('http://graph.facebook.com/alswblog/').read()
json_data = json.loads(data)
print ('%s') % (json_data['hours']['mon_1_open'])
