// 004292a0 FUN_004292a0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004292a0(void *this,int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)((int)this + 0x10) * *(float *)(param_1 + 0x10) +
          *(float *)((int)this + 0xc) * *(float *)(param_1 + 0xc) +
          *(float *)((int)this + 4) * *(float *)(param_1 + 4) +
          *(float *)((int)this + 8) * *(float *)(param_1 + 8);
  if ((byte)(fVar1 < _DAT_00473438 |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00473438)) << 10) >> 8)) == 1) {
    *(float *)((int)this + 4) = *(float *)((int)this + 4) * _DAT_00473440;
    *(float *)((int)this + 8) = *(float *)((int)this + 8) * _DAT_00473440;
    *(float *)((int)this + 0xc) = *(float *)((int)this + 0xc) * _DAT_00473440;
    *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) * _DAT_00473440;
  }
  return;
}


