要求 python 3.9.4  ， 我安装 3.10好像也可以

# 抓取抖音礼物程序的目录是  `tikk`

### 安装依赖
```bash
pip install requests
pip install protobuf==3.20.2
pip install websocket-client
pip install httpx
pip install pyserial
# pip install tkinter       # 这个会报错， 不过好像也没关系
pip install pyinstaller
pip install APScheduler
```

## 乒乓球 table_tennis
#### 直接运行  自动发射乒乓球
```bash
python dytxt_table_tennis.py
```

#### 打包程序输出exe执行文件 自动发射乒乓球
打包命令
``` bash
pyinstaller -w -F dytxt_table_tennis.py   # 前提你得安装pyinstaller
```


## 弹珠 marble
#### 直接运行  自动发射乒乓球
```bash
python dytxt_marble.py
```

#### 打包程序输出exe执行文件 自动发射乒乓球
打包命令
``` bash
pyinstaller -w -F dytxt_marble.py   # 前提你得安装pyinstaller
```
