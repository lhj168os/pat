import requests
from bs4 import BeautifulSoup
newsurl = 'http://www.7kk.com'
res = requests.get(newsurl)
res.econding = 'utf-8'
soup = BeautifulSoup(res.text)
print(soup.text)    
