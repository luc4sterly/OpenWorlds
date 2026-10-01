// 00433336 FUN_00433336 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_00433336(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  undefined4 in_EAX;
  short *psVar1;
  int extraout_ECX;
  int iVar2;
  int extraout_EDX;
  undefined8 local_1c;
  
  psVar1 = &DAT_00437d64;
  if (param_5 < 0) {
    iVar2 = -param_5;
    if (param_5 == -0x134 || iVar2 < 0x134) goto LAB_004333e3;
    if ((DAT_0043e7e4 & 1) != 0) {
      psVar1 = (short *)__adj_fdiv_m64(DAT_00437d66,DAT_00437d6a);
      param_5 = extraout_ECX;
      iVar2 = extraout_EDX;
    }
  }
  else {
    iVar2 = param_5;
    if (param_5 < 0x135) goto LAB_004333e3;
  }
  iVar2 = iVar2 + -0xd8;
LAB_004333e3:
  local_1c = 1.0;
  while( true ) {
    if (*psVar1 <= iVar2) {
      local_1c = local_1c * *(double *)(psVar1 + 1);
      iVar2 = iVar2 - *psVar1;
    }
    if (iVar2 == 0) break;
    if (*psVar1 != 1) {
      psVar1 = psVar1 + 5;
    }
  }
  if ((param_5 < 0) && ((DAT_0043e7e4 & 1) != 0)) {
    __adj_fdiv_m64((undefined4)local_1c,local_1c._4_4_);
  }
  return CONCAT44(param_2,in_EAX);
}


