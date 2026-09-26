// 004065f1 FUN_004065f1 [Global]
// programa: gdkup.exe

uint __fastcall FUN_004065f1(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  ushort in_FPUControlWord;
  undefined4 local_18;
  
  local_18 = 0;
  if ((DAT_00408f44 != '\0') && (local_18 = (uint)in_FPUControlWord, param_2 != 0)) {
    local_18 = ~param_2 & local_18 | param_2 & in_EAX & 0xffff;
  }
  return local_18;
}


