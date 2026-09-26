// 1000ca50 FUN_1000ca50 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_1000ca50(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    uVar5 = *(uint *)(*param_1 + 8);
    bVar1 = *(byte *)((param_1[2] >> 0x10) * 0x20 + ((uVar5 & 0x7c0) >> 6) + 0x400 + DAT_10087248);
    bVar2 = *(byte *)((param_1[1] >> 0x10) * 0x20 + ((uVar5 & 0xf800) >> 0xb) + DAT_10087248);
    piVar6 = param_1 + 0xf;
    bVar3 = *(byte *)((param_1[3] >> 0x10) * 0x20 + (uVar5 & 0x1f) + 0x800 + DAT_10087248);
    uVar5 = (uint)*(byte *)((int)param_1 + 0x3a);
    while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
      iVar4 = *piVar6;
      piVar6 = piVar6 + 1;
      if ((*(byte *)(iVar4 + 0x48) & 0x3f) == 0) {
        *(ushort *)
         (*(int *)(DAT_10087240 + (*(int *)(iVar4 + 0x1c) >> 0x10) * 4) +
         (*(int *)(iVar4 + 0x18) >> 0x10) * 2) =
             (ushort)bVar1 << 6 | (ushort)bVar2 << 0xb | (ushort)bVar3;
      }
    }
  }
  return 0;
}


