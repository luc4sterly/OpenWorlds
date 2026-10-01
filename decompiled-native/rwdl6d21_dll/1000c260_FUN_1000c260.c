// 1000c260 FUN_1000c260 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_1000c260(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    uVar1 = *(ushort *)(*param_1 + 8);
    uVar5 = (uint)*(byte *)((int)param_1 + 0x3a);
    piVar3 = param_1 + 0xf;
    while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
      iVar2 = *piVar3;
      piVar3 = piVar3 + 1;
      if ((*(byte *)(iVar2 + 0x48) & 0x3f) == 0) {
        puVar6 = (ushort *)
                 ((*(int *)(iVar2 + 0x1c) >> 0x10) * DAT_1007beb0 +
                  (*(int *)(iVar2 + 0x18) >> 0x10) * 2 + DAT_10079210);
        uVar4 = ((int)((uint)*(byte *)(*param_1 + 0x30) << 0x19) >> 0x1f & 0xff0000U) +
                *(int *)(iVar2 + 0x20);
        if ((uint)*puVar6 < uVar4 >> 0x10) {
          *puVar6 = (ushort)(uVar4 >> 0x10);
          *(ushort *)
           (*(int *)(DAT_10079218 + (*(int *)(iVar2 + 0x1c) >> 0x10) * 4) +
           (*(int *)(iVar2 + 0x18) >> 0x10) * 2) =
               (ushort)*(byte *)((*(int *)(iVar2 + 0x5c) >> 0x10) * 0x20 +
                                 (uint)((uVar1 & 0x7c0) >> 6) + 0x400 + DAT_10079220) << 6 |
               (ushort)*(byte *)((*(int *)(iVar2 + 0x58) >> 0x10) * 0x20 + (uint)(uVar1 >> 0xb) +
                                DAT_10079220) << 0xb |
               (ushort)*(byte *)((*(int *)(iVar2 + 0x60) >> 0x10) * 0x20 + (uVar1 & 0x1f) + 0x800 +
                                DAT_10079220);
        }
      }
    }
  }
  return 0;
}


