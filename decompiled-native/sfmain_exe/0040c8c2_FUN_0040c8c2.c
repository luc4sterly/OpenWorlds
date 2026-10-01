// 0040c8c2 FUN_0040c8c2 [Global]
// program: sfmain.exe

void __fastcall FUN_0040c8c2(int param_1,undefined4 *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 *unaff_EBX;
  uint auStack_44 [14];
  
  if (in_EAX == 0) {
    auStack_44[1] = *param_2;
    auStack_44[2] = *unaff_EBX;
    auStack_44[3] = 0;
    puVar6 = (uint *)(param_1 + 0x28);
    iVar4 = 4;
    do {
      uVar2 = *puVar6;
      iVar3 = iVar4 + 4;
      puVar6 = puVar6 + -1;
      *(uint *)((int)auStack_44 + iVar4 + 0xc) = uVar2 & 0x7fff;
      iVar4 = iVar3;
    } while (iVar3 != 0x2c);
    iVar4 = 1;
    puVar6 = param_3;
    do {
      puVar6 = puVar6 + 1;
      *puVar6 = auStack_44[*(int *)(iVar4 * 4 + 0x43911c)] & 1;
      iVar3 = *(int *)(iVar4 * 4 + 0x43911c);
      iVar4 = iVar4 + 1;
      auStack_44[iVar3] = (int)auStack_44[iVar3] >> 1;
    } while (iVar4 < 0x36);
    param_3[0x36] = DAT_004452cc & 1;
    DAT_004452cc = 1 - DAT_004452cc;
  }
  else if (in_EAX == 1) {
    auStack_44[0] = 0x40c981;
    FUN_0042bdf7(0xd,0);
    iVar4 = 0xd0;
    puVar6 = param_3 + 0x35;
    do {
      piVar1 = (int *)((int)&DAT_00439120 + iVar4);
      iVar4 = iVar4 + -4;
      uVar2 = *puVar6;
      puVar6 = puVar6 + -1;
      auStack_44[*piVar1] = auStack_44[*piVar1] * 2 + uVar2;
    } while (iVar4 != -4);
    iVar4 = 4;
    do {
      if ((*(uint *)((int)auStack_44 + iVar4 + 0xc) & *(uint *)((int)&DAT_004390f4 + iVar4)) != 0) {
        *(uint *)((int)auStack_44 + iVar4 + 0xc) =
             *(int *)((int)auStack_44 + iVar4 + 0xc) + *(uint *)((int)&DAT_004390f4 + iVar4) * -2;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 != 0x2c);
    *param_2 = auStack_44[1];
    *unaff_EBX = auStack_44[2];
    puVar5 = (undefined4 *)(param_1 + 4);
    iVar4 = 0x30;
    do {
      *puVar5 = *(undefined4 *)((int)auStack_44 + iVar4 + 4);
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + -4;
    } while (puVar5 != (undefined4 *)(param_1 + 0x2c));
  }
  return;
}


