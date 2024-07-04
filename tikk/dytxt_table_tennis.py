# -*- coding: utf-8 -*-
import tkinter

from requests import RequestException
from websocket import WebSocketApp
import re
import gzip,httpx
import webcast_proto2_pb2
import tkinter as tk
from tkinter import ttk
import threading
import time
import serial.tools.list_ports
import serial
import json
from pathlib import Path

"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)
_sym_db = _symbol_database.Default()
DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x0c\x64ouyin.proto\x12\x06\x64ouyin\")\n\x0bHeadersList\x12\x0b\n\x03key\x18\x01 \x01(\t\x12\r\n\x05value\x18\x02 \x01(\t\"\xb3\x01\n\tPushFrame\x12\r\n\x05seqId\x18\x01 \x01(\x04\x12\r\n\x05logId\x18\x02 \x01(\x04\x12\x0f\n\x07service\x18\x03 \x01(\x04\x12\x0e\n\x06method\x18\x04 \x01(\x04\x12(\n\x0bheadersList\x18\x05 \x03(\x0b\x32\x13.douyin.HeadersList\x12\x17\n\x0fpayloadEncoding\x18\x06 \x01(\t\x12\x13\n\x0bpayloadType\x18\x07 \x01(\t\x12\x0f\n\x07payload\x18\x08 \x01(\x0c\"\x9a\x01\n\x07Message\x12\x0e\n\x06method\x18\x01 \x01(\t\x12\x0f\n\x07payload\x18\x02 \x01(\x0c\x12\r\n\x05msgId\x18\x03 \x01(\x03\x12\x0f\n\x07msgType\x18\x04 \x01(\x05\x12\x0e\n\x06offset\x18\x05 \x01(\x03\x12\x15\n\rneedWrdsStore\x18\x06 \x01(\x08\x12\x13\n\x0bwrdsVersion\x18\x07 \x01(\x03\x12\x12\n\nwrdsSubKey\x18\x08 \x01(\t\"\xe4\x02\n\x08Response\x12%\n\x0cmessagesList\x18\x01 \x03(\x0b\x32\x0f.douyin.Message\x12\x0e\n\x06\x63ursor\x18\x02 \x01(\t\x12\x15\n\rfetchInterval\x18\x03 \x01(\x04\x12\x0b\n\x03now\x18\x04 \x01(\x04\x12\x13\n\x0binternalExt\x18\x05 \x01(\t\x12\x11\n\tfetchType\x18\x06 \x01(\r\x12\x36\n\x0brouteParams\x18\x07 \x03(\x0b\x32!.douyin.Response.RouteParamsEntry\x12\x19\n\x11heartbeatDuration\x18\x08 \x01(\x04\x12\x0f\n\x07needAck\x18\t \x01(\x08\x12\x12\n\npushServer\x18\n \x01(\t\x12\x12\n\nliveCursor\x18\x0b \x01(\t\x12\x15\n\rhistoryNoMore\x18\x0c \x01(\x08\x1a\x32\n\x10RouteParamsEntry\x12\x0b\n\x03key\x18\x01 \x01(\t\x12\r\n\x05value\x18\x02 \x01(\t:\x02\x38\x01\"S\n\x0b\x43hatMessage\x12\x1a\n\x04user\x18\x02 \x01(\x0b\x32\x0c.douyin.User\x12\x0f\n\x07\x63ontent\x18\x03 \x01(\t\x12\x17\n\x0fvisibleToSender\x18\x04 \x01(\x08\"\x9a\x01\n\x04User\x12\n\n\x02id\x18\x01 \x01(\x04\x12\x0f\n\x07shortId\x18\x02 \x01(\x04\x12\x10\n\x08nickName\x18\x03 \x01(\t\x12\x0e\n\x06gender\x18\x04 \x01(\r\x12\x11\n\tSignature\x18\x05 \x01(\t\x12\r\n\x05Level\x18\x06 \x01(\r\x12\x10\n\x08\x42irthday\x18\x07 \x01(\x04\x12\x11\n\tTelephone\x18\x08 \x01(\t\x12\x0c\n\x04\x63ity\x18\x0e \x01(\tb\x06proto3')
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'douyin_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:
  DESCRIPTOR._options = None
  _RESPONSE_ROUTEPARAMSENTRY._options = None
  _RESPONSE_ROUTEPARAMSENTRY._serialized_options = b'8\001'
  _HEADERSLIST._serialized_start=24
  _HEADERSLIST._serialized_end=65
  _PUSHFRAME._serialized_start=68
  _PUSHFRAME._serialized_end=247
  _MESSAGE._serialized_start=250
  _MESSAGE._serialized_end=404
  _RESPONSE._serialized_start=407
  _RESPONSE._serialized_end=763
  _RESPONSE_ROUTEPARAMSENTRY._serialized_start=713
  _RESPONSE_ROUTEPARAMSENTRY._serialized_end=763
  _CHATMESSAGE._serialized_start=765
  _CHATMESSAGE._serialized_end=848
  _USER._serialized_start=851
  _USER._serialized_end=1005
# @@protoc_insertion_point(module_scope)



def write_to_log(message):
    log_text.insert(tk.END, message + "\n")
    log_text.update_idletasks()
    log_text.see(tk.END)  # 确保滚动条在最底部
def live_info(url):
    try:
        res = httpx.get(
            url=url,
            headers = {
                'authority': 'douyin.com',
                'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
                'accept-language': 'zh-CN,zh;q=0.9,en;q=0.8',
                'cache-control': 'no-cache',
                'cookie': 'device_web_cpu_core=16; device_web_memory_size=8; xgplayer_user_id=463421106069; csrf_session_id=edf738231761a5147197973003809c11; webcast_leading_last_show_time=1694172613110; webcast_leading_total_show_times=1; webcast_local_quality=sd; ttwid=1%7CCXcnzcrsWub9rrnTk6VgAeMEKNq7MZy-Wdvg1UaPYGQ%7C1701928743%7C5dc0c9b315e2dd9feca70d6145c819071b42bc5b42a47dd73af13f8de4b34869; passport_csrf_token=8acc2de7b02b210e7df0fa8ca5e61009; passport_csrf_token_default=8acc2de7b02b210e7df0fa8ca5e61009; bd_ticket_guard_client_web_domain=2; FORCE_LOGIN=%7B%22videoConsumedRemainSeconds%22%3A180%2C%22isForcePopClose%22%3A1%7D; live_use_vvc=%22false%22; odin_tt=536f43455243c02f23b3f7d5de057073417fc22a1030f314eb8463954fe7cea95b86298f7c03e9c02d497aebe02817adc0fc4cea15527fca65c95b71ed968f5e0cc09b6bf95057e36624886254075255; download_guide=%223%2F20231221%2F0%22; ttcid=3d6ce9de911a4eb1a67e2fb7d67497bf41; webcast_local_quality=sd; volume_info=%7B%22isUserMute%22%3Afalse%2C%22isMute%22%3Afalse%2C%22volume%22%3A0.5%7D; stream_recommend_feed_params=%22%7B%5C%22cookie_enabled%5C%22%3Atrue%2C%5C%22screen_width%5C%22%3A1536%2C%5C%22screen_height%5C%22%3A864%2C%5C%22browser_online%5C%22%3Atrue%2C%5C%22cpu_core_num%5C%22%3A16%2C%5C%22device_memory%5C%22%3A8%2C%5C%22downlink%5C%22%3A10%2C%5C%22effective_type%5C%22%3A%5C%224g%5C%22%2C%5C%22round_trip_time%5C%22%3A150%7D%22; SEARCH_RESULT_LIST_TYPE=%22single%22; strategyABtestKey=%221703646674.962%22; home_can_add_dy_2_desktop=%221%22; bd_ticket_guard_client_data=eyJiZC10aWNrZXQtZ3VhcmQtdmVyc2lvbiI6MiwiYmQtdGlja2V0LWd1YXJkLWl0ZXJhdGlvbi12ZXJzaW9uIjoxLCJiZC10aWNrZXQtZ3VhcmQtcmVlLXB1YmxpYy1rZXkiOiJCSDV1ODRzV0RVNUNLUStrV29pY3VwTXVIQW54TlQwVXdHcmhyYlJpUy9aL0dWSk8wbG8wWm5VM2c0bHV5WmdiR2VyVHM4clRibTV1L3V3d2VUTmtNQmc9IiwiYmQtdGlja2V0LWd1YXJkLXdlYi12ZXJzaW9uIjoxfQ%3D%3D; stream_player_status_params=%22%7B%5C%22is_auto_play%5C%22%3A1%2C%5C%22is_full_screen%5C%22%3A0%2C%5C%22is_full_webscreen%5C%22%3A0%2C%5C%22is_mute%5C%22%3A0%2C%5C%22is_speed%5C%22%3A1%2C%5C%22is_visible%5C%22%3A0%7D%22; __live_version__=%221.1.1.6573%22; __ac_nonce=0658b95de0017b6239414; __ac_signature=_02B4Z6wo00f01jLbBRgAAIDDUdHFcjMDnP4y-wGAAOlLxg4cWDe8qNUcaJmaIXqVuTl5J2.d2VPavMw3D8Q3vlgUPWe9yv1O1RLNVqMnEaKIA2qb6D41y7X3qUcxsgX7f4p.HimFS.SDlheh4a; xg_device_score=7.90435294117647; msToken=LMWbS1oDACsCIqAoJzixfCStaqDhzcqqPR0MqZLJVAD-M3Gl3_cy54vFOgkleGOu2EOTbWSM5ix65av4592yiRFX1z7iD2XVewutmL56GgGC1xsq27RNZCwpECesyQ==; tt_scid=L3aNknPQWgS3h-xdRuBNCwcAp2yCJyMhBD6sajTHIkmiS0HUGo1XJWZs0Ct7IPUY1218; pwa2=%220%7C0%7C3%7C0%22; webcast_leading_last_show_time=1703646868651; webcast_leading_total_show_times=4; live_can_add_dy_2_desktop=%221%22; msToken=regBtpnAohlBr086hglLC1nzxd6p1KQP9b_WKDmFEkjbZz43YIyM0GNcFf0ZPnFC5IipW_ble4i0bDvxicJWLHxfRFi76epsrI6YZ5Lv8MceOm-m5FiVuwSeqJCaCw==; IsDouyinActive=false',
                'pragma': 'no-cache',
                'referer': 'https://douyin.com/',
                'sec-ch-ua': '"Google Chrome";v="119", "Chromium";v="119", "Not?A_Brand";v="24"',
                'sec-ch-ua-mobile': '?0',
                'sec-ch-ua-platform': '"Windows"',
                'sec-fetch-dest': 'document',
                'sec-fetch-mode': 'navigate',
                'sec-fetch-site': 'same-origin',
                'sec-fetch-user': '?1',
                'upgrade-insecure-requests': '1',
                'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36',
            },
            cookies={
                "__ac_nonce": "063abcffa00ed8507d599"  # 可以是任意值
            }
        )
    except Exception as e:
        return -1, '', 'room_title', 'room_user_count', 'wss_url', 'ttwid'
    room_id = re.findall(r'\\"roomId\\":\\"(.*?)\\"', res.text)[0]
    room_title = ''
    room_user_count =''
    # enc=f"live_id=1,aid=6383,version_code=180800,webcast_sdk_version=1.0.8,room_id={room_id},sub_room_id=,sub_channel_id=,did_rule=3,user_unique_id=,device_platform=web,device_type=,ac=,identity=audience"
    # enc=f"live_id=1,aid=6383,version_code=180800,webcast_sdk_version=1.0.12,room_id={room_id},sub_room_id=,sub_channel_id=,did_rule=3,user_unique_id=7309728240302016034,device_platform=web,device_type=,ac=,identity=audience"
    # sign=execjs.compile(open('sign.js',encoding='utf8').read()).call('sign',md5(enc.encode()).hexdigest())
    sign=httpx.get('http://119.23.175.61:8866/sign?room_id='+room_id).json()['sign']
    wss_url=f'wss://webcast5-ws-web-lq.douyin.com/webcast/im/push/v2/?app_name=douyin_web&version_code=180800&webcast_sdk_version=1.0.12&update_version_code=1.0.12&compress=gzip&device_platform=web&cookie_enabled=true&screen_width=1536&screen_height=864&browser_language=zh-CN&browser_platform=Win32&browser_name=Mozilla&browser_version=5.0%20(Windows%20NT%2010.0;%20Win64;%20x64)%20AppleWebKit/537.36%20(KHTML,%20like%20Gecko)%20Chrome/119.0.0.0%20Safari/537.36&browser_online=true&tz_name=Asia/Shanghai&cursor=t-1703251890105_r-1_d-1_u-1_fh-7315409832168641573&internal_ext=internal_src:dim|wss_push_room_id:{room_id}|wss_push_did:7309728240302016034|dim_log_id:202312222131295DBE730567E4322E82E2|first_req_ms:1703251889982|fetch_time:1703251890105|seq:1|wss_info:0-1703251890105-0-0|wrds_kvs:WebcastActivityEmojiGroupsMessage-1703247544419620387_WebcastRoomStreamAdaptationMessage-1703251871345099618_WebcastInRoomBannerMessage-GrowthCommonBannerASubSyncKey-1703251614011692005_LotteryInfoSyncData-1703250711729232057_WebcastRoomStatsMessage-1703251888588310545_DoubleLikeSyncData-1703251618744190204_WebcastRoomRankMessage-1703251880101553898&host=https://live.douyin.com&aid=6383&live_id=1&did_rule=3&endpoint=live_pc&support_wrds=1&user_unique_id=7309728240302016034&im_path=/webcast/im/fetch/&identity=audience&need_persist_msg_count=15&room_id={room_id}&heartbeatDuration=0&signature={sign["X-Bogus"]}'
    # wss_url=f'wss://webcast5-ws-web-hl.douyin.com/webcast/im/push/v2/?app_name=douyin_web&version_code=180800&webcast_sdk_version=1.0.8&update_version_code=1.0.8&compress=gzip&device_platform=web&cookie_enabled=true&screen_width=1536&screen_height=864&browser_language=zh-CN&browser_platform=Win32&browser_name=Mozilla&browser_version=5.0%20(Windows%20NT%2010.0;%20Win64;%20x64)%20AppleWebKit/537.36%20(KHTML,%20like%20Gecko)%20Chrome/114.0.0.0%20Safari/537.36&browser_online=true&tz_name=Asia/Shanghai&cursor=r-1_d-1_u-1_h-1_t-1692620078416&internal_ext=internal_src:dim|wss_push_room_id:{room_id}|wss_push_did:7268909383177553447|dim_log_id:202308212014381EDBA25C71790E20C55A|first_req_ms:1692620078342|fetch_time:1692620078416|seq:1|wss_info:0-1692620078416-0-0|wrds_kvs:WebcastRoomRankMessage-1692619896739112291_WebcastRoomStatsMessage-1692620076734383562&host=https://live.douyin.com&aid=6383&live_id=1&did_rule=3&endpoint=live_pc&support_wrds=1&user_unique_id=&im_path=/webcast/im/fetch/&identity=audience&room_id={room_id}&heartbeatDuration=0&signature={sign["X-Bogus"]}'
    ttwid = res.cookies['ttwid']
    return 0, room_id, room_title, room_user_count, wss_url, ttwid
def on_open(ws):
    global on_error_status
    if on_error_status == 0:
        print('on_open...')

def on_message(ws, content):
    global balls,gift_tmp_array,gift_tmp_array_idx,ff,chat_txt_array,chat_ball,gift_txt_array,gift_ball

    frame = PushFrame()
    frame.ParseFromString(content)
    # 对PushFrame的 payload 内容进行gzip解压
    origin_bytes = gzip.decompress(frame.payload)
    # 根据Response+gzip解压数据，生成数据对象
    response = Response()
    response.ParseFromString(origin_bytes)
    needs =['WebcastChatMessage','WebcastGiftMessage']

    data = dict()
    data['message'] = list()
    if response.needAck:
        s = PushFrame()
        s.payloadType = "ack"
        s.payload = response.internalExt.encode('utf-8')
        s.logId = frame.logId
        ws.send(s.SerializeToString())

    for message in response.messagesList:
        if message.method not in needs:
            continue
        #print(message)
        data['message'].append(parse_message(message))
    if data['message'] != []:
        for i in data['message']:
            #key = i['id']
            #if key not in uid_list:
            #    uid_list.append(key)
            #else:
            #    continue
            #write_to_log(str(i))

            if i['type'] == "WebcastChatMessage":
                if i['content'] in chat_txt_array:
                    write_to_log(i['nickname'] + " 发送弹幕 " + i['content'])
                    balls += int(chat_ball[chat_txt_array.index(i['content'])])

            elif i['type'] == "WebcastGiftMessage":
                tmp4 = i['nickname'] + i['content'] + str(i['unique_id'])
                if tmp4 not in gift_tmp_array:
                    write_to_log(i['nickname'] + " 发送礼物 " + i['content'])
                    gei = i['content'].find("个")
                    if gei > 0:
                        gei_x = i['content'][0:gei]
                        gei_content = i['content'][gei+1:]
                        if gei_content in gift_txt_array:
                            balls += int(gei_x) * int(gift_ball[gift_txt_array.index(gei_content)])

                    ff.write(str(i))
                    ff.write('\n')
                    gift_tmp_array[gift_tmp_array_idx] = tmp4
                    gift_tmp_array_idx = gift_tmp_array_idx + 1
                    if gift_tmp_array_idx >= 20:
                        gift_tmp_array_idx = 0



on_error_status=0
def on_error(ws, content):
    global stopping,on_error_status
    if on_error_status == 0:
        print("on_error")
        print(content)
        write_to_log("=====================>程序报错，正在结束======")
        write_to_log(str(content))
        write_to_log("=====================>程序重新启动======")
        on_error_status = 1
    start_ws()


def on_close(ws, content, ppp):
    global on_error_status
    if on_error_status == 0:
        print("on_close")

def parse_message(message: webcast_proto2_pb2.mwebcastimMessage):
    def parse_time(timestamp):
        time_local = time.localtime(timestamp // 1000)
        return time.strftime("%Y-%m-%d %H:%M:%S", time_local) + '  => '
    # 谁来了
    if message.method == 'WebcastMemberMessage':
        MemberMessage = webcast_proto2_pb2.rwebcastimMemberMessage()
        MemberMessage.ParseFromString(message.payload)  # 解密完成
        if len(MemberMessage.common.displayText.pieces) == 1:
            data = {
                'type': 'WebcastMemberMessage',
                'content': MemberMessage.common.displayText.defaultPattern.replace('{0:user}',
                                                                                   MemberMessage.common.displayText.pieces[
                                                                                       0].userValue.user.nickname).replace(
                    '{1:string}', ''),
                'nickname': MemberMessage.user.nickname,  # 用户名
                'sec_uid': MemberMessage.user.secUid,  # 用户sec_id
                'id': MemberMessage.user.id,  # 用户id
                'short_id': MemberMessage.user.shortId,  # 用户短id
                'gender': MemberMessage.user.gender,  # 1男2女0未知
                'unique_id': MemberMessage.user.displayId,  # 抖音id
            }
            return data
        else:
            raise Exception("入场文字")
    # 送礼
    elif message.method == 'WebcastGiftMessage':
        GiftMessage = webcast_proto2_pb2.rwebcastimGiftMessage()
        GiftMessage.ParseFromString(message.payload)
        #print(GiftMessage)
        data = {
            'type': 'WebcastGiftMessage',
            'content': GiftMessage.common.describe.split(" ")[-1],
            'nickname': GiftMessage.user.nickname,  # 用户名
            'sec_uid': GiftMessage.user.secUid,  # 用户sec_id
            'id': GiftMessage.user.id,  # 用户id
            'short_id': GiftMessage.user.shortId,  # 用户短id
            'gender': GiftMessage.user.gender,  # 1男2女0未知
            'unique_id': GiftMessage.groupId,       #.user.displayId,  # 抖音id
        }
        return data
    # 点赞
    elif message.method == 'WebcastLikeMessage':#点赞

        LikeMessage = webcast_proto2_pb2.rwebcastimLikeMessage()
        LikeMessage.ParseFromString(message.payload)
        # print(
        #     parse_time(int(time.time() * 1000)) + LikeMessage.user.nickname + '为主播点赞，总赞数：' + str(LikeMessage.total))
        data = {
            'type': 'WebcastLikeMessage',
            'content': '点赞',
            'nickname': LikeMessage.user.nickname,  # 用户名
            'sec_uid': LikeMessage.user.secUid,  # 用户sec_id
            'id': LikeMessage.user.id,  # 用户id
            'short_id': LikeMessage.user.shortId,  # 用户短id
            'gender': LikeMessage.user.gender,  # 1男2女0未知
            'unique_id': LikeMessage.user.displayId,  # 抖音id
        }
        return data
    # 观众前三名# 返回前10，只有前3显示名字
    elif message.method == 'WebcastRoomUserSeqMessage':#观众前三名
        RoomUserSeqMessage = webcast_proto2_pb2.rwebcastimRoomUserSeqMessage()
        RoomUserSeqMessage.ParseFromString(message.payload)
        data_key=parse_time(int(time.time() * 1000)) + '观众前三排名：【' + ' >>> '.join(
            [i.user.nickname for i in RoomUserSeqMessage.ranks[:3]]) + '】' # 返回前10，只有前3显示名字
        data={
            'type':'WebcastRoomUserSeqMessage',
            'content':data_key}
        return data
    # 小时榜
    elif message.method == 'WebcastSunDailyRankMessage':#小时榜
        SunDailyRankMessage = webcast_proto2_pb2.rwebcastimSunDailyRankMessage()
        SunDailyRankMessage.ParseFromString(message.payload)
        # print(parse_time(
        #     SunDailyRankMessage.common.createTime) + SunDailyRankMessage.afterContent + '   ' + SunDailyRankMessage.content)  # 小时榜
        data = {
            'type': 'WebcastSunDailyRankMessage',
            'content':SunDailyRankMessage.afterContent +'|'+ SunDailyRankMessage.content}
        return data
    # 评论弹幕
    elif message.method == 'WebcastChatMessage':  # 评论弹幕
        ChatMessage = webcast_proto2_pb2.rwebcastimChatMessage()
        ChatMessage.ParseFromString(message.payload)
        data = {
            'type': 'WebcastChatMessage',
            'nickname': ChatMessage.user.nickname,  # 用户名
            'content': ChatMessage.content,  # 用户内容
            'sec_uid': ChatMessage.user.secUid,  # 用户sec_id
            'id': ChatMessage.user.id,  # 用户id
            'short_id': ChatMessage.user.shortId,  # 用户短id
            'gender': ChatMessage.user.gender,  # 1男2女0未知
            'unique_id': ChatMessage.user.displayId,  # 抖音id
        }
        return data
    # 关注主播
    elif message.method == 'WebcastSocialMessage':#关注主播
        SocialMessage = webcast_proto2_pb2.rwebcastimSocialMessage()
        SocialMessage.ParseFromString(message.payload)
        # print(parse_time(int(time.time() * 1000)) + SocialMessage.common.displayText.defaultPattern.replace(
        #     '{0:user}', SocialMessage.common.displayText.pieces[0].userValue.user.nickname) + '，总粉丝数：' + str(
        #     SocialMessage.followCount))
        data = {
            'type': 'WebcastSocialMessage',
            'nickname': SocialMessage.user.nickname,  # 用户名
            'content': "关注了主播",  # 用户内容
            'sec_uid': SocialMessage.user.secUid,  # 用户sec_id
            'id': SocialMessage.user.id,  # 用户id
            'short_id': SocialMessage.user.shortId,  # 用户短id
            'gender': SocialMessage.user.gender,  # 1男2女0未知
            'unique_id': SocialMessage.user.displayId,  # 抖音id
        }
        return data
    # 直播间欢迎语
    elif message.method == 'WebcastRoomMessage':#直播间欢迎语
        RoomMessage = webcast_proto2_pb2.rwebcastimRoomMessage()
        RoomMessage.ParseFromString(message.payload)
        # print(parse_time(RoomMessage.common.createTime) + RoomMessage.content)
        data = {
            'type': 'WebcastRoomMessage',
            'content': '未知type'}
        return data
    elif message.method == 'WebcastRoomIntroMessage':
        RoomIntroMessage = webcast_proto2_pb2.rwebcastimRoomIntroMessage()
        RoomIntroMessage.ParseFromString(message.payload)

        # print(parse_time(
        #     int(time.time() * 1000)) + RoomIntroMessage.user.nickname + ' [直播间简介] ' + RoomIntroMessage.intro)  # 直播间简介
        data = {
            'type': 'WebcastRoomIntroMessage',
            'content': RoomIntroMessage.intro}
        return data
    elif message.method == 'WebcastRoomNotifyMessage':
        RoomNotifyMessage = webcast_proto2_pb2.rwebcastimRoomNotifyMessage()
        RoomNotifyMessage.ParseFromString(message.payload)
        # print(RoomNotifyMessage)
        # print(RoomNotifyMessage.common.displayText.defaultPattern)
        # print(RoomNotifyMessage.common.displayText.pieces[0].stringValue)
        # print(RoomNotifyMessage.common.displayText.pieces[1].stringValue)
        # print(RoomNotifyMessage.common.displayText.pieces[2].stringValue)
        # print(RoomNotifyMessage.user.nickname)
        data = {
            'type': 'WebcastRoomNotifyMessage',
            'content': "未知type"}
        return data
    elif message.method == 'WebcastScreenChatMessage':#直播间欢迎语
        ScreenChatMessage = webcast_proto2_pb2.rwebcastimScreenChatMessage()
        ScreenChatMessage.ParseFromString(message.payload)
        # print(parse_time(
        #     int(time.time() * 1000)) + '【屏幕信息】 ' + ScreenChatMessage.user.nickname + '： ' + ScreenChatMessage.content)  # 公屏信息
        data = {
            'type': 'WebcastScreenChatMessage',
            'content': ScreenChatMessage.content}
        return data
    # 加入粉丝团
    elif message.method == 'WebcastFansclubMessage':
        FansclubMessage = webcast_proto2_pb2.rwebcastimFansclubMessage()
        FansclubMessage.ParseFromString(message.payload)
        # print(parse_time(FansclubMessage.common.createTime) + FansclubMessage.content)  # 加入粉丝团
        data = {
            'type': 'WebcastFansclubMessage',
            'nickname': FansclubMessage.user.nickname,  # 用户名
            'content': FansclubMessage.content.split(" ")[-1].strip(),  # 用户内容
            'sec_uid': FansclubMessage.user.secUid,  # 用户sec_id
            'id': FansclubMessage.user.id,  # 用户id
            'short_id': FansclubMessage.user.shortId,  # 用户短id
            'gender': FansclubMessage.user.gender,  # 1男2女0未知
            'unique_id': FansclubMessage.user.displayId,  # 抖音id
        }

        return data
    elif message.method == 'WebcastAudioChatMessage':
        AudioChatMessage = webcast_proto2_pb2.rwebcastimAudioChatMessage()
        AudioChatMessage.ParseFromString(message.payload)
        # print(parse_time(
        #     int(time.time() * 1000)) + '【音频信息】 ' + AudioChatMessage.user.nickname + '： ' + AudioChatMessage.content)  # 音频信息
        # # audio_url = AudioChatMessage.audio_url
        data = {
            'type': 'WebcastAudioChatMessage',
            'content': '未知type'}
        return data
    # 总票数
    elif message.method == 'WebcastUpdateFanTicketMessage':
        UpdateFanTicketMessage = webcast_proto2_pb2.rwebcastimUpdateFanTicketMessage()
        UpdateFanTicketMessage.ParseFromString(message.payload)
        # print(UpdateFanTicketMessage)
        data_key=str(UpdateFanTicketMessage).split(":")[-1].strip()
        data = {
            'type': 'WebcastUpdateFanTicketMessage',
            'content': data_key}
        return data
    elif message.method == 'WebcastControlMessage':
        ControlMessage = webcast_proto2_pb2.rwebcastimControlMessage()
        ControlMessage.ParseFromString(message.payload)
        # print(ControlMessage)
        data = {
            'type': 'WebcastControlMessage',
            'content': '未知type'}
        return data
    # 表情
    elif message.method == 'WebcastEmojiChatMessage':
        EmojiChatMessage = webcast_proto2_pb2.rwebcastimEmojiChatMessage()
        EmojiChatMessage.ParseFromString(message.payload)
        # print(EmojiChatMessage)
        # print(EmojiChatMessage.user.nickname)
        # print(EmojiChatMessage.default_content)
        # print(parse_time(int(time.time() * 1000)) + '【表情信息】 ' +
        #       EmojiChatMessage.emoji_content.pieces[0].imageValue.image.urlList[0])  # 音频信息
        data = {
            'type': 'WebcastEmojiChatMessage',
            'content': '未知type'}
        return data
    elif message.method == 'WebcastDoubleLikeHeartMessage':
        DoubleLikeHeartMessage = webcast_proto2_pb2.rwebcastimDoubleLikeHeartMessage()
        DoubleLikeHeartMessage.ParseFromString(message.payload)
        # print(DoubleLikeHeartMessage)
        data = {
            'type': 'WebcastDoubleLikeHeartMessage',
            'content': '未知type'}
        return data
    # 送礼人气票
    elif message.method == 'WebcastGiftVoteMessage':
        GiftVoteMessage = webcast_proto2_pb2.rwebcastimGiftVoteMessage()
        GiftVoteMessage.ParseFromString(message.payload)
        print("人气票")
        print(GiftVoteMessage)
        data = {
            'type': 'WebcastGiftVoteMessage',
            'nickname': GiftVoteMessage.user.nickname,  # 用户名
            'content': GiftVoteMessage.content,  # 用户内容
            'sec_uid': GiftVoteMessage.user.secUid,  # 用户sec_id
            'id': GiftVoteMessage.id,  # 用户id
            'short_id': GiftVoteMessage.user.shortId,  # 用户短id
            'gender': GiftVoteMessage.user.gender,  # 1男2女0未知
            'unique_id': GiftVoteMessage.user.displayId,  # 抖音id
        }
        return data
    elif message.method == 'WebcastLinkMicGuideMessage':
        LinkMicGuideMessage = webcast_proto2_pb2.rwebcastimLinkMicGuideMessage()
        LinkMicGuideMessage.ParseFromString(message.payload)
        # print(LinkMicGuideMessage)
        data = {
            'type': 'WebcastLinkMicGuideMessage',
            'content': '未知type'}
        return data
    else:
        with open(message.method + '.base64', 'wb') as f:
            f.write(message.payload)
            '''
            https://live.douyin.com/webcast/user/?aid=6383&live_id=1&device_platform=web&language=zh-CN&target_uid=111111&sec_target_uid=MS4wLjABAAAAvOEA4the1TgVpfU5Fqb1deZnw4gfJ1oxOYMEZNIHwqU
            '''

room_id=0
room_title=0
room_user_count=0
wss_url=0
ttwid=0

def run(web_url):
    global ws,room_id,room_title,room_user_count,wss_url,ttwid
    live_status=-1
#    for i in web_url.split(','):
    # web_url = "https://live.douyin.com/567789235524"
    print("run testtest.")
    while live_status == -1:
        live_status, room_id, room_title, room_user_count, wss_url, ttwid = live_info(web_url)
    print("run testtest q.")

    ws = WebSocketApp(
        url=wss_url,
        header={
                'Pragma': 'no-cache',
                'Origin': 'https://live.douyin.com',
                'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
                'Sec-WebSocket-Key': 'IVcHb4wVkV7TD7K/iAWSdw==',
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36',
                'Upgrade': 'websocket',
                'Cache-Control': 'no-cache',
                'Connection': 'Upgrade',
                'Sec-WebSocket-Version': '13',
                'Sec-WebSocket-Extensions': 'permessage-deflate; client_max_window_bits',
        },
        cookie=f"ttwid={ttwid}",
        on_open=on_open,
        on_message=on_message,
        on_error=on_error,
        on_close=on_close,
    )
    wst = threading.Thread(target=ws.run_forever)
    wst.setDaemon(True)
    wst.start()

# 输出时间

send_job_run = False
send_job_isrunning = False
def send_job():
    global send_job_run,send_job_isrunning
    print("send_job start.")
    send_job_isrunning = True

    global balls
    while send_job_run:
        if balls > 0:
            if len(combobox['values']) > 0:
                selection = combobox.get()
                ser = serial.Serial(selection, 9600)
                # message = f"" + str(int(gei_x) * int(gift_ball[gift_txt_array.index(gei_content)])) + "\n"  # 使用bytes对象发送消息
                # ser.write(message.encode("utf-8"))

                message = bytes.fromhex('A0 01 01 A2')
                ser.write(message)
                balls_tmp = balls
                balls = 0
                write_to_log("    ==>串口发送释放" + str(balls_tmp) + "个小球")
                time.sleep(2.8 * balls_tmp)
                message = bytes.fromhex('A0 01 00 A1')
                ser.write(message)

                ser.close()
            else:
                time.sleep(1)
                write_to_log("==>没有串口设备")

    send_job_isrunning = False
    print("send_job stop.")


t_send = threading.Thread()

def start_collection():
    # global redis_client,redis_client2
    global uid_list,ff,send_job_run,t_send,balls

    if send_job_isrunning:
        write_to_log("===============================>发球中，请勿重复进入<==================")
        return

    uid_list=[]
    url = live_room_entry.get()
    if len(url) == 0:
        write_to_log("===============================>请输入直播间地址<==================")
        return

    write_to_log("===============================>启动中...<==================")
    balls = 0
    filename = url.split('/')[-1] + '.txt'

    ff = open(filename, 'a+',encoding='utf8')

    #等待发送线程结束
    if t_send:
        while send_job_isrunning:
            send_job_run = False

    send_job_run = True
    t_send = threading.Thread(target=run, args=(url,))
    t_send.setDaemon(True)
    t_send.start()
    print("t_send.start()")

    t1 = threading.Thread(target=send_job, args=())
    t1.setDaemon(True)
    t1.start()
    print("t1.start()")
    write_to_log("===============================>启动成功<==================")


def start_connect():
    # global redis_client,redis_client2
    global uid_list,ff,send_job_run,t_send,balls

    uid_list=[]
    url = live_room_entry.get()
    if len(url) == 0:
        write_to_log("===============================>请输入直播间地址<==================")
        return

    write_to_log("===============================>启动中...<==================")
    balls = 0
    filename = url.split('/')[-1] + '.txt'

    ff = open(filename, 'a+',encoding='utf8')

    t_send = threading.Thread(target=run, args=(url,))
    t_send.setDaemon(True)
    t_send.start()
    print("t_send.start()")
    write_to_log("===============================>启动成功<==================")

def start_ws():
    global ws,room_id,room_title,room_user_count,wss_url,ttwid
    ws = WebSocketApp(
        url=wss_url,
        header={
                'Pragma': 'no-cache',
                'Origin': 'https://live.douyin.com',
                'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
                'Sec-WebSocket-Key': 'IVcHb4wVkV7TD7K/iAWSdw==',
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36',
                'Upgrade': 'websocket',
                'Cache-Control': 'no-cache',
                'Connection': 'Upgrade',
                'Sec-WebSocket-Version': '13',
                'Sec-WebSocket-Extensions': 'permessage-deflate; client_max_window_bits',
        },
        cookie=f"ttwid={ttwid}",
        on_open=on_open,
        on_message=on_message,
        on_error=on_error,
        on_close=on_close,
    )
    wst = threading.Thread(target=ws.run_forever)
    wst.setDaemon(True)
    wst.start()

stopping = 0
def stop_collection():
    global send_job_run,t_send,balls,stopping
    # 停止 WebSocket 连接
    # global ws
    if ws:
        ws.close()

    #等待发送线程结束
    if t_send:
        write_to_log("===============================>发球中，请等待结束<==================")
        while send_job_isrunning:
            send_job_run = False
    write_to_log("===============================>发球已结束<==================")
    send_job_run = False

    balls = 0
    print("stop_collection finished.")

#停止网络连接
def stop_connect():
    global send_job_run,t_send,balls,stopping,t_send
    # 停止 WebSocket 连接
    # global ws
    if ws:
        ws.close()
    stopping = 0
    print("stop_connect finished.")


com_ports = []
for port in serial.tools.list_ports.comports():
    com_ports.append(port.name)
print(com_ports)

def on_selection_change(event):
    # 获取选中的值
    selection = combobox.get()
    print("选中的值:", selection)
    ser = serial.Serial(selection, 9600)

    # 发送消息
    message = b'Hello, Serial Port!\n'  # 使用bytes对象发送消息
    ser.write(message)

    # 关闭串口
    ser.close()

gift_txt_array = []
gift_ball = []
chat_txt_array = []
chat_ball = []
balls = 0
gift_tmp_array = ["","","","","","","","","","","","","","","","","","","",""]
gift_tmp_array_idx = 0



def comm_add_to_list():
    global config1
    gift_txt = comm_gift_entry.get()
    if len(gift_txt) == 0:
        return
    comm_table.insert(tkinter.END, f"收到礼物 “" + gift_txt + "” 释放 " + comm_ball_combobox.get() + "个球")
    gift_txt_array.append(gift_txt)
    gift_ball.append(comm_ball_combobox.get())
    gift = {"gift_txt":gift_txt,"gift_ball":comm_ball_combobox.get(),"gif_type": "WebcastGiftMessage"}
    config1.append(gift)
    with open('config1.json', 'w', encoding='utf8') as file:
        json.dump(config1, file, indent=4)

def comm_add_to_list2():
    global config2
    chat_txt = comm_gift_entry2.get()
    if len(chat_txt) == 0:
        return
    comm_table2.insert(tkinter.END, f"收到礼物 “" + chat_txt + "” 释放 " + comm_ball_combobox2.get() + "个球")
    chat_txt_array.append(chat_txt)
    chat_ball.append(comm_ball_combobox2.get())
    chat = {"gift_txt":chat_txt,"gift_ball":comm_ball_combobox2.get(),"gif_type": "WebcastChatMessage"}
    config2.append(chat)
    with open('config2.json', 'w', encoding='utf8') as file:
        json.dump(config2, file, indent=4)


def comm_remove_from_list():
    global config1
    if(len(comm_table.curselection())>0):
        gift_txt_array.pop(comm_table.curselection()[0])
        gift_ball.pop(comm_table.curselection()[0])
        config1.pop(comm_table.curselection()[0])
        with open('config1.json', 'w', encoding='utf8') as file:
            json.dump(config1, file, indent=4)

        comm_table.delete(comm_table.curselection())


def comm_remove_from_list2():
    global config2
    if(len(comm_table2.curselection())>0):
        chat_txt_array.pop(comm_table2.curselection()[0])
        chat_ball.pop(comm_table2.curselection()[0])
        config2.pop(comm_table2.curselection()[0])
        with open('config2.json', 'w', encoding='utf8') as file:
            json.dump(config2, file, indent=4)

        comm_table2.delete(comm_table2.curselection())




file_tmp = Path("config1.json")
if file_tmp.exists() == False:
    config1 = [{"gift_txt":"小心心", "gift_ball":"1","gif_type": "WebcastGiftMessage"}]
    with open('config1.json', 'w', encoding='utf8') as file:
        json.dump(config1, file, indent=4)
file_tmp = Path("config2.json")
if file_tmp.exists() == False:
    config2 = [{"gift_txt":"666", "gift_ball":"1","gif_type": "WebcastChatMessage"}]
    with open('config2.json', 'w', encoding='utf8') as file:
        json.dump(config2, file, indent=4)

root = tk.Tk()
root.title("直播间采集")
root.geometry("910x600")
logs = {}

live_room_frame = tk.Frame(root)
live_room_frame.pack(fill=tk.X, padx=10, pady=5)
live_room_label = tk.Label(live_room_frame, text="直播间链接:")
live_room_label.pack(side=tk.LEFT)
live_room_entry = tk.Entry(live_room_frame, width=50, font=("Helvetica", 16))
live_room_entry.pack(side=tk.LEFT, expand=True, fill=tk.X)
combobox = ttk.Combobox(live_room_frame, width=20)
combobox["values"] = com_ports  # 设置下拉列表的值
combobox.bind("<<ComboboxSelected>>", on_selection_change)  # 绑定事件，当选项变更时触发
if len(combobox['values']) > 0:
    combobox.current(0)  # 设置默认选中第一项
combobox.pack(side=tk.LEFT, fill=tk.X, padx=10)

comm_frame2 = tk.Frame(root)
comm_frame2.pack(fill=tk.X, padx=0, pady=5)
comm_gift_label = tk.Label(comm_frame2, text="收到礼物:")
comm_gift_label.pack(side=tk.LEFT, padx=10)
comm_gift_entry = tk.Entry(comm_frame2, width=20)
comm_gift_entry.pack(side=tk.LEFT, fill=tk.X)
comm_ball_label = tk.Label(comm_frame2, text="释放球:")
comm_ball_label.pack(side=tk.LEFT, padx=10)
comm_ball_combobox = ttk.Combobox(comm_frame2, width=5)
comm_ball_combobox["values"] = (1,2,3,4,5,6,7,8,9)  # 设置下拉列表的值
comm_ball_combobox.current(0)  # 设置默认选中第一项
comm_ball_combobox.pack(side=tk.LEFT, fill=tk.X, padx=0)
comm_balls_label = tk.Label(comm_frame2, text="个")
comm_balls_label.pack(side=tk.LEFT, padx=0)
comm_button = tk.Button(comm_frame2, text="添加", command=comm_add_to_list, width=5)
comm_button.pack(side=tk.LEFT, fill=tk.X, padx=20)


comm_gift_label2 = tk.Label(comm_frame2, text="收到弹幕:")
comm_gift_label2.pack(side=tk.LEFT, padx=10)
comm_gift_entry2 = tk.Entry(comm_frame2, width=20)
comm_gift_entry2.pack(side=tk.LEFT, padx=0)
comm_ball_label2 = tk.Label(comm_frame2, text="释放球:")
comm_ball_label2.pack(side=tk.LEFT, padx=10)
comm_ball_combobox2 = ttk.Combobox(comm_frame2, width=5)
comm_ball_combobox2["values"] = (1,2,3,4,5,6,7,8,9)  # 设置下拉列表的值
comm_ball_combobox2.current(0)  # 设置默认选中第一项
comm_ball_combobox2.pack(side=tk.LEFT, fill=tk.X, padx=0)
comm_balls_label2 = tk.Label(comm_frame2, text="个")
comm_balls_label2.pack(side=tk.LEFT, padx=0)
comm_button2 = tk.Button(comm_frame2, text="添加", command=comm_add_to_list2, width=5)
comm_button2.pack(side=tk.LEFT, fill=tk.X, padx=10)

config1 = []
config2 = []


comm_table_frame = tk.Frame(root)
comm_table_frame.pack(fill=tk.X, padx=10, pady=5)
comm_table = tkinter.Listbox(comm_table_frame, selectmode=tkinter.BROWSE, width=60)
comm_table.pack(side=tk.LEFT, fill=tk.X)
with open('config1.json', 'r',encoding='utf8') as file:
    config1 = json.load(file)
for c1 in config1:
    comm_table.insert(tkinter.END,f"收到礼物 “" + c1['gift_txt'] + "” 释放 " + c1['gift_ball'] + "个球")
    gift_txt_array.append(c1['gift_txt'])
    gift_ball.append(c1['gift_ball'])
comm_table2 = tkinter.Listbox(comm_table_frame, selectmode=tkinter.BROWSE, width=60)
comm_table2.pack(side=tk.LEFT, fill=tk.X, padx=25)
with open('config2.json', 'r',encoding='utf8') as file:
    config2 = json.load(file)
for c1 in config2:
    comm_table2.insert(tkinter.END,f"收到弹幕 “" + c1['gift_txt'] + "” 释放 " + c1['gift_ball'] + "个球")
    chat_txt_array.append(c1['gift_txt'])
    chat_ball.append(c1['gift_ball'])


button_frame = tk.Frame(root)
button_frame.pack(fill=tk.X, padx=10, pady=5)
comm_table_del_button = tk.Button(button_frame, text="删除选中行", command=comm_remove_from_list, width=10)
comm_table_del_button.pack(side=tk.LEFT, padx=10)
comm_table_del_button2 = tk.Button(button_frame, text="删除选中行", command=comm_remove_from_list2, width=10)
comm_table_del_button2.pack(side=tk.LEFT, padx=360)

log_frame = tk.Frame(root)
log_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=5)
log_label = tk.Label(log_frame, text="日志:")
log_label.pack(anchor=tk.W)
log_text = tk.Text(log_frame, height=10, width=50)
log_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)


scrollbar = tk.Scrollbar(log_frame, command=log_text.yview)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
log_text.config(yscrollcommand=scrollbar.set)

button_frame = tk.Frame(root)
button_frame.pack(fill=tk.X, padx=10, pady=5)
start_button = tk.Button(button_frame, text="开始采集", command=start_collection)
start_button.pack(side=tk.LEFT, expand=True, fill=tk.X)
stop_button = tk.Button(button_frame, text="停止采集", command=stop_collection)
stop_button.pack(side=tk.LEFT, expand=True, fill=tk.X)


if __name__ == '__main__':
    root.mainloop()
