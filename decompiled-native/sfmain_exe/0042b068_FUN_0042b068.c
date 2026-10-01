// 0042b068 FUN_0042b068 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042b068(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  UINT UVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0042ba46(param_1,param_2);
  puVar1 = (undefined4 *)uVar3;
  *puVar1 = in_EAX;
  puVar1[1] = 0;
  UVar2 = RegisterWindowMessageA(s_VoiceChatAlert_004377b8);
  puVar1[2] = UVar2;
  return CONCAT44(param_2,puVar1);
}


