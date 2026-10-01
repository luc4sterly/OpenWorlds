// 004046e6 FUN_004046e6 [Global]
// program: gdkup.exe

longlong __fastcall FUN_004046e6(undefined4 param_1,uint param_2)

{
  uint *in_EAX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = *in_EAX + 0xb & 0xfffffff8;
  uVar2 = 0;
  if (uVar1 == 0) {
LAB_0040472d:
    return CONCAT44(param_2,uVar2);
  }
  *in_EAX = uVar1;
  uVar1 = uVar1 + 0x3c;
  if (*in_EAX <= uVar1) {
    if (uVar1 < DAT_00408f24) {
      uVar1 = DAT_00408f24 & 0xfffffffe;
    }
    *in_EAX = uVar1;
    if (*in_EAX <= uVar1 + 0xfff) {
      uVar2 = uVar1 + 0xfff >> 8 & 0xfffff0;
      *in_EAX = uVar2 << 8;
      uVar2 = (uint)(uVar2 != 0);
      goto LAB_0040472d;
    }
  }
  return (ulonglong)param_2 << 0x20;
}


