import requests
import base64

url = 'http://59.64.78.184:6003/'

s = requests.session()
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:50.0) Gecko/20100101 Firefox/50.0'}
html = s.get(url,headers=headers)
print(html.headers)
flag = html.headers['flag'].encode()
flag = base64.b64decode(flag)
print (flag)

data = {
	'flag':flag
}
r = s.post(url,data=data,headers=headers)
print (r.text)
