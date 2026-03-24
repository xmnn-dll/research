shared::DeviceInfo *__fastcall shared::DeviceInfo::DeviceInfo(shared::DeviceInfo *this, __int64 a2)
{
  __int64 v6; // [rsp+20h] [rbp-29h]
  __int64 v7; // [rsp+20h] [rbp-29h]
  __int64 v8; // [rsp+20h] [rbp-29h]
  __int64 v9; // [rsp+20h] [rbp-29h]
  __int64 v10; // [rsp+20h] [rbp-29h]
  __int64 v11; // [rsp+20h] [rbp-29h]
  __int64 v12; // [rsp+20h] [rbp-29h]
  __int64 v13; // [rsp+20h] [rbp-29h]
  __int64 v14; // [rsp+20h] [rbp-29h]
  __int64 v15; // [rsp+20h] [rbp-29h]
  __int64 v16; // [rsp+20h] [rbp-29h]
  __int64 v17; // [rsp+20h] [rbp-29h]
  __int64 v18; // [rsp+20h] [rbp-29h]
  __int64 v19; // [rsp+20h] [rbp-29h]
  _BYTE v20[32]; // [rsp+30h] [rbp-19h] BYREF
  _BYTE v21[16]; // [rsp+50h] [rbp+7h] BYREF
  __m128i v22; // [rsp+60h] [rbp+17h]
  _BYTE v23[16]; // [rsp+70h] [rbp+27h] BYREF
  __m128i si128; // [rsp+80h] [rbp+37h]

  memset_0(this, 0, 0x250u);
  shared::DeviceInfo::DeviceInfo(this);
  si128 = _mm_load_si128((const __m128i *)&_xmm);
  v23[0] = 0;
  v22 = si128;
  v21[0] = 0;
  std::string::string(v20, "deviceId");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, this, v20, 0, this);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "name");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 32, v20, 0, v6);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "endpoints");
  cdp::Serializer<cdp::JsonData>::GetValue<std::vector<shared::Endpoint>,std::vector<shared::Endpoint>>(
    a2,
    (char *)this + 64,
    v20);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "connectionModes");
  cdp::Serializer<cdp::JsonData>::GetValue<enum shared::ActivityBlockedOperationFlags,enum shared::ActivityBlockedOperationFlags>(
    a2,
    (char *)this + 90,
    v20);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "status");
  cdp::Serializer<cdp::JsonData>::GetValue<unsigned int,unsigned int>(a2, (char *)this + 96, v20, 0);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "type");
  cdp::Serializer<cdp::JsonData>::GetValue<enum shared::ActivityBlockedOperationFlags,enum shared::ActivityBlockedOperationFlags>(
    a2,
    (char *)this + 88,
    v20);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "isMyDevice");
  cdp::Serializer<cdp::JsonData>::GetValue<bool,bool>(a2, (char *)this + 128, v20, 0);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "extendedDeviceStatus");
  cdp::Serializer<cdp::JsonData>::GetValue<enum cdp::CommandServiceCloudNotificationType,enum cdp::CommandServiceCloudNotificationType>(
    a2,
    (char *)this + 232,
    v20);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "DeviceThumbprint");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 248, v20, 0, v7);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "UserDeviceThumbprint");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 280, v20, 0, v8);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "CcsTicket");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 312, v20, 0, v9);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "CcsTicketExpiration");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, v21, v20, 0, v10);
  std::string::_Tidy_deallocate(v20);
  CDP_DATE_TIME::FromString((char *)this + 344, v21);
  std::string::string(v20, "BluetoothClassicMacAddress");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 376, v20, 0, v11);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "IpV4Address");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 408, v20, 0, v12);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "ShortOSVersion");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 440, v20, 0, v13);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "ManufacturerName");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 472, v20, 0, v14);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "ModelName");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 504, v20, 0, v15);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "Applications");
  cdp::Serializer<cdp::JsonData>::GetValue<std::vector<shared::CDPApplication>,std::vector<shared::CDPApplication>>(
    a2,
    (char *)this + 536,
    v20,
    0);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "ApplicationId");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 136, v20, 0, v16);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "DeduplicationHint");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 168, v20, 0, v17);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "DeviceDdsClientId");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 200, v20, 0, v18);
  std::string::_Tidy_deallocate(v20);
  std::string::string(v20, "ApplicationDisplayName");
  cdp::Serializer<cdp::JsonData>::GetValue<std::string,std::string>(a2, (char *)this + 560, v20, 0, v19);
  std::string::_Tidy_deallocate(v20);
  std::string::_Tidy_deallocate(v21);
  std::string::_Tidy_deallocate(v23);
  return this;
}
