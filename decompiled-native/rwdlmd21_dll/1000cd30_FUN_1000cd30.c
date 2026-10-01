// 1000cd30 FUN_1000cd30 [Global]
// program: rwdlmd21.dll

undefined4 FUN_1000cd30(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    uVar1 = *(ushort *)(*param_1 + 8);
    uVar4 = (uint)*(byte *)((int)param_1 + 0x3a);
    piVar3 = param_1 + 0xf;
    while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
      iVar2 = *piVar3;
      piVar3 = piVar3 + 1;
      if ((*(byte *)(iVar2 + 0x48) & 0x3f) == 0) {
        puVar6 = (ushort *)
                 ((*(int *)(iVar2 + 0x1c) >> 0x10) * DAT_10089ef4 +
                  (*(int *)(iVar2 + 0x18) >> 0x10) * 2 + DAT_10087238);
        uVar5 = ((int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000U) +
                *(int *)(iVar2 + 0x20);
        if ((uint)*puVar6 < uVar5 >> 0x10) {
          *puVar6 = (ushort)(uVar5 >> 0x10);
          *(ushort *)
           (*(int *)(DAT_10087240 + (*(int *)(iVar2 + 0x1c) >> 0x10) * 4) +
           (*(int *)(iVar2 + 0x18) >> 0x10) * 2) =
               (ushort)*(byte *)((*(int *)(iVar2 + 0x5c) >> 0x10) * 0x20 +
                                 (uint)((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10087248) << 6 |
               (ushort)*(byte *)((*(int *)(iVar2 + 0x58) >> 0x10) * 0x20 + (uint)(uVar1 >> 0xb) +
                                DAT_10087248) << 0xb |
               (ushort)*(byte *)((*(int *)(iVar2 + 0x60) >> 0x10) * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                DAT_10087248);
        }
      }
    }
  }
  return 0;
}


