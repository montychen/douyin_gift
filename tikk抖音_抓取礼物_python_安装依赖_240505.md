要求 python 3.9.4  ， 我安装 3.10好像也可以 

# 安装依赖
```bash
pip install protobuf==3.20.2                           
pip install websocket-client
pip install tkinter       # 这个会报错， 不过好像也没关系
pip install pyinstaller
```

# 打包程序 pyinstaller
打包命令
``` bash
pyinstaller -w -F dytxt.py   # 前提你得安装pyinstaller
```