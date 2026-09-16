// 0040c540 FUN_0040c540 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040c540(void)

{
  bool bVar1;
  int iVar2;
  uint unaff_EBX;
  uint uVar3;
  int unaff_EBP;
  uint uVar4;
  
  if (unaff_EBX == 0) {
    return 0;
  }
  bVar1 = false;
  *(undefined1 *)(unaff_EBP + -0x1c) = 0;
  if ((unaff_EBX < 5) && (unaff_EBX != 0)) {
    bVar1 = true;
  }
  if ((bVar1) && (unaff_EBX != 3)) {
    *(undefined1 *)(unaff_EBP + -0x1c) = 1;
  }
  *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xff;
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    SendMessageA((HWND)**(undefined4 **)(unaff_EBP + -0x18),0x8065,
                 *(uint *)(unaff_EBP + -0x10) | _DAT_0046e8a0,0);
  }
  uVar4 = unaff_EBX >> 5;
  uVar3 = 1 << ((byte)unaff_EBX & 0x1f);
  *(uint *)(unaff_EBP + -0x14) = uVar3;
  if ((uVar3 & *(uint *)(&DAT_0048927c + uVar4 * 4)) != 0) {
    if (*(int *)(unaff_EBP + -0x1c) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 5;
    }
    FUN_0040c2c0(*(void **)(unaff_EBP + -0x18),iVar2,unaff_EBX);
    *(uint *)(&DAT_0048927c + uVar4 * 4) = *(uint *)(&DAT_0048927c + uVar4 * 4) & ~uVar3;
  }
  if (*(int *)(unaff_EBP + -0x10) == 0) {
    if (*(int *)(unaff_EBP + -0x1c) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 5;
    }
    FUN_0040c2c0(*(void **)(unaff_EBP + -0x18),iVar2,unaff_EBX);
  }
  else {
    if (*(int *)(unaff_EBP + -0x1c) == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 4;
    }
    FUN_0040c2c0(*(void **)(unaff_EBP + -0x18),iVar2,unaff_EBX);
    *(uint *)(&DAT_0048927c + uVar4 * 4) =
         *(uint *)(&DAT_0048927c + uVar4 * 4) | *(uint *)(unaff_EBP + -0x14);
  }
  return 1;
}


