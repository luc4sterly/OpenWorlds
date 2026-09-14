// 0041a110 FUN_0041a110 [Global]
// programa: gamma.dll

undefined8 __fastcall FUN_0041a110(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_004895b0 = param_3;
  DAT_004895ac = RwOpenDisplayDevice(param_3,0);
  return CONCAT44(param_2,DAT_004895ac);
}


