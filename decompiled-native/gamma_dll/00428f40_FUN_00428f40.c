// 00428f40 FUN_00428f40 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00428f40(void *this,int param_1,float param_2)

{
  ushort in_FPUStatusWord;
  float10 fVar1;
  float10 fVar2;
  float10 extraout_ST1;
  
  *(undefined ***)this = &PTR_LAB_00473828;
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0xc);
  fVar1 = (float10)param_2 * (float10)_DAT_00473420;
  fVar2 = (float10)fsin(fVar1);
  if ((in_FPUStatusWord & 0x400) != 0) {
    fVar2 = FUN_0044d970();
    fVar2 = (float10)fsin(fVar2);
  }
  fVar2 = (float10)(float)fVar2;
  fVar1 = (float10)fcos(fVar1);
  if ((in_FPUStatusWord & 0x400) != 0) {
    fVar1 = FUN_0044d970();
    fVar1 = (float10)fcos(fVar1);
    fVar2 = extraout_ST1;
  }
  *(float *)((int)this + 4) = (float)fVar1;
  *(float *)((int)this + 8) = (float)((float10)*(float *)((int)this + 8) * fVar2);
  *(float *)((int)this + 0xc) = (float)((float10)*(float *)((int)this + 0xc) * fVar2);
  *(float *)((int)this + 0x10) = (float)((float10)*(float *)((int)this + 0x10) * fVar2);
  FUN_00429070((int)this);
  return this;
}


