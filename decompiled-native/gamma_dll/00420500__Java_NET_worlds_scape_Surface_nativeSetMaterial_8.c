// 00420500 _Java_NET_worlds_scape_Surface_nativeSetMaterial@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Surface_nativeSetMaterial_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* 0x20500  303  _Java_NET_worlds_scape_Surface_nativeSetMaterial@8 */
  uVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049ff58);
  iVar3 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar2);
  uVar4 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049ff34);
  uVar4 = FUN_00416fd0(param_1,uVar4);
  iVar5 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar4);
  iVar6 = (**(code **)(*param_1 + 0x2ec))(param_1,uVar2,0);
  iVar7 = (**(code **)(*param_1 + 0x2ec))(param_1,uVar4,0);
  iVar8 = 0;
  iVar9 = 0;
  if (0 < iVar3) {
    do {
      iVar1 = *(int *)(iVar6 + iVar9 * 4);
      if (iVar1 != 0) {
        FUN_00419fc0(iVar1,*(undefined4 *)(iVar7 + iVar8 * 4));
      }
      iVar8 = iVar8 + 1;
      if (iVar8 == iVar5) {
        iVar8 = 0;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar3);
  }
  (**(code **)(*param_1 + 0x30c))(param_1,uVar2,iVar6,0);
  (**(code **)(*param_1 + 0x30c))(param_1,uVar4,iVar7,0);
  return;
}


