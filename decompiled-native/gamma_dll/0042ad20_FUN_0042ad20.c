// 0042ad20 FUN_0042ad20 [Global]
// programa: gamma.dll

int __thiscall FUN_0042ad20(void *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 1;
  while (param_1 !=
         *(short *)(&DAT_004740b4 + (uVar2 + (int)*(short *)(&DAT_00473e98 + param_1 * 2)) * 2)) {
    param_1 = (int)*(short *)(&DAT_00473f30 + param_1 * 2);
    if (0x48 < param_1) {
      uVar2 = (uint)(byte)(&DAT_00473e30)[uVar2 * 4];
    }
  }
  iVar3 = (int)*(short *)(&DAT_00473fc8 + (uVar2 + (int)*(short *)(&DAT_00473e98 + param_1 * 2)) * 2
                         );
  if (iVar3 == 0x48) {
    iVar3 = 0;
  }
  else {
    piVar1 = *(int **)((int)this + 0x50);
    *(int *)((int)this + 0x50) = *(int *)((int)this + 0x50) + 4;
    *piVar1 = iVar3;
  }
  return iVar3;
}


