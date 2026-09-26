// 0042f49b FUN_0042f49b [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042f49b(undefined4 param_1,undefined4 param_2)

{
  uint *in_EAX;
  _SYSTEMTIME local_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = param_2;
  uStack_8 = param_1;
  GetLocalTime(&local_1c);
  in_EAX[5] = local_1c.wYear - 0x76c;
  in_EAX[4] = local_1c.wMonth - 1;
  in_EAX[3] = (uint)local_1c.wDay;
  in_EAX[2] = (uint)local_1c.wHour;
  in_EAX[1] = (uint)local_1c.wMinute;
  in_EAX[8] = 0xffffffff;
  *in_EAX = (uint)local_1c.wSecond;
  return CONCAT44(uStack_c,(uint)local_1c.wMilliseconds);
}


