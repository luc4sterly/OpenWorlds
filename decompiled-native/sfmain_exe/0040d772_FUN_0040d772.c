// 0040d772 FUN_0040d772 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0040d772(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined8 uVar1;
  uint local_20;
  
  DAT_004393a4 = FUN_0042c438(param_1,&DAT_00435abc);
  if (DAT_004393a4 == 0) {
    DAT_004393a4 = FUN_0042c438(extraout_ECX,&DAT_00435ac0);
  }
  if (DAT_004393a4 != 0) {
    FUN_0042c5e5(0x800,0x44531c);
    FUN_0042c6a0(extraout_ECX_00,0);
    uVar1 = FUN_0042c794(extraout_ECX_01,extraout_EDX);
    DAT_00445b1c = (undefined4)uVar1;
    FUN_0042c7e5(extraout_ECX_02);
  }
  _DAT_004393a8 = 0;
  local_20 = (uint)(DAT_004393a4 != 0);
  return CONCAT44(param_2,local_20);
}


