// 00428e60 FUN_00428e60 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00428e60(void *this,int param_1)

{
  byte bVar1;
  undefined2 extraout_var;
  float10 fVar2;
  
  fVar2 = FUN_00429090((int)this,param_1);
  bVar1 = ABS((float)(fVar2 - (float10)_DAT_00473414)) < _DAT_00473418 |
          (byte)((ushort)((ushort)(NAN(ABS((float)(fVar2 - (float10)_DAT_00473414))) ||
                                  NAN(_DAT_00473418)) << 10) >> 8);
  return CONCAT31(CONCAT21(extraout_var,bVar1),bVar1 == 1);
}


