// 1000cc40 FUN_1000cc40 [Global]
// program: rwdlmd21.dll

undefined4 FUN_1000cc40(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    uVar1 = *(uint *)(*param_1 + 8);
    piVar4 = param_1 + 0xf;
    uVar3 = (uint)*(byte *)((int)param_1 + 0x3a);
    while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
      iVar2 = *piVar4;
      piVar4 = piVar4 + 1;
      if ((*(byte *)(iVar2 + 0x48) & 0x3f) == 0) {
        *(ushort *)
         (*(int *)(DAT_10087240 + (*(int *)(iVar2 + 0x1c) >> 0x10) * 4) +
         (*(int *)(iVar2 + 0x18) >> 0x10) * 2) =
             (ushort)*(byte *)((*(int *)(iVar2 + 0x5c) >> 0x10) * 0x20 + ((uVar1 & 0x7c0) >> 6) +
                               0x400 + DAT_10087248) << 6 |
             (ushort)*(byte *)((*(int *)(iVar2 + 0x58) >> 0x10) * 0x20 + ((uVar1 & 0xf800) >> 0xb) +
                              DAT_10087248) << 0xb |
             (ushort)*(byte *)((*(int *)(iVar2 + 0x60) >> 0x10) * 0x20 + (uVar1 & 0x1f) + 0x800 +
                              DAT_10087248);
      }
    }
  }
  return 0;
}


