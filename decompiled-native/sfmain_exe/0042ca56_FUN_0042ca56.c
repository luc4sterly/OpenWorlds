// 0042ca56 FUN_0042ca56 [Global]
// programa: sfmain.exe

uint __fastcall FUN_0042ca56(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  ushort in_FPUControlWord;
  undefined4 local_18;
  
  local_18 = 0;
  if ((DAT_0043e520 != '\0') && (local_18 = (uint)in_FPUControlWord, param_2 != 0)) {
    local_18 = ~param_2 & local_18 | param_2 & in_EAX & 0xffff;
  }
  return local_18;
}


