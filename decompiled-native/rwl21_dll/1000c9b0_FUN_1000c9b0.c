// 1000c9b0 FUN_1000c9b0 [Global]
// programa: RWL21.DLL

undefined4 FUN_1000c9b0(undefined *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 4;
    *(undefined1 **)(PTR_DAT_1005b69c + iVar3 + 0x54) = &LAB_1000cb00;
    iVar3 = iVar2;
  } while (iVar2 < 0x200);
  *(undefined4 *)(PTR_DAT_1005b69c + 0x270) = 0;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x44) = 0;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x278) = 0;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x27c) = 0;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x280) = 0;
  *(undefined1 **)(PTR_DAT_1005b69c + 0x260) = &LAB_1000cb10;
  *(undefined1 **)(PTR_DAT_1005b69c + 0x264) = &LAB_1000cb20;
  *(undefined1 **)(PTR_DAT_1005b69c + 0x268) = &LAB_1000cb40;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x298) = 0;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x29c) = 0;
  *(undefined1 **)(PTR_DAT_1005b69c + 0x28c) = &LAB_1000cb50;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x1c) = 4;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x28) = 0x2160000;
  if (param_1 == (undefined *)0x0) {
    *(uint *)(PTR_DAT_1005b69c + 0x28) = *(uint *)(PTR_DAT_1005b69c + 0x28) & 0xffff;
    return 1;
  }
  iVar3 = (*(code *)param_1)(PTR_DAT_1005b69c + 0x14);
  if (iVar3 == 0) {
    *(uint *)(PTR_DAT_1005b69c + 0x28) = *(uint *)(PTR_DAT_1005b69c + 0x28) & 0xffff;
    return 0;
  }
  uVar1 = *(uint *)(PTR_DAT_1005b69c + 0x28);
  if ((uVar1 & 0xffff0000) == 0x2160000) {
    *(uint *)(PTR_DAT_1005b69c + 0x28) = uVar1 & 0xffff;
    (**(code **)(PTR_DAT_1005b69c + 0x25c))();
    return 0;
  }
  if ((uVar1 & 0xffff0000) != 0) {
    return 0;
  }
  *(uint *)(PTR_DAT_1005b69c + 0x28) = uVar1 & 0xffff;
  return 1;
}


