import datetime
import requests
import json
import csv

url = 'http://r.webdev.com/pageView/exportCmpData'
# url = 'http://usering.webdev.com/usering/Downloader/test'

postData = {
    'expPage': '渠道日活跃用户',
    'expPageId': '1049200',
    'expCmpId': 'table_6',
    'expParams': {
        'headname': ['日期','系统','渠道ID','渠道名称','日活用户数'],
        'totalCount': 1000,
        'params': {
            '_datakey': '',
            '_user': 'xtcheng',
            'iPageId': '1049200',
            'iDesignId': '1031536', 
            'sCmpId': 'table_6',
            'dataSrc': 'sql',
            'sPropName': 'sql',
            'queryParam': 'startDate=__SD__&endDate=__ED__&ifromid=all&ostype=android%2Cios&col=dau',
            'forName': 'data',
            'tdName': ['imp_date','ostype','ifromid','name','v1'],
            'sortField': 1,
            'sortType': 'desc'
        }
    }
}

eDate = (datetime.date.today() - datetime.timedelta(days=1)).strftime('%Y%m%d')
sDate = (datetime.date.today() - datetime.timedelta(days=1)).strftime('%Y%m%d')
queryParam = postData['expParams']['params']['queryParam']
queryParam = queryParam.replace('__ED__', eDate)
queryParam = queryParam.replace('__SD__', sDate)
postData['expParams']['params']['queryParam'] = queryParam
postData['expParams']['params'] = json.dumps(postData['expParams']['params'])

print(postData)
cookies = {
    'PAS_COOKIE_USER': 'edwinxfmeng',
    'PAS_COOKIE_TICKET': '5e77537fbb1a2162'
}
rsp = requests.post(url, data = postData, cookies=cookies)

