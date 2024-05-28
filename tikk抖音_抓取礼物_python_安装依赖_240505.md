要求 python 3.9.4  ， 我安装 3.10好像也可以

# 安装依赖
```bash
pip install protobuf==3.20.2
pip install websocket-client
pip install httpx
pip install pyserial
pip install tkinter       # 这个会报错， 不过好像也没关系
pip install pyinstaller
pip install APScheduler
```

# 自动发射乒乓球
把这个文件 `dytxt_table_tennis` 替换掉`tikk/dytxt.py`文件

# 直接运行
```bash
python dytxt.py
```

# 打包程序 pyinstaller
打包命令
``` bash
pyinstaller -w -F dytxt.py   # 前提你得安装pyinstaller
```
