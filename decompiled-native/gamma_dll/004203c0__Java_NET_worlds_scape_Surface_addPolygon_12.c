// 004203c0 _Java_NET_worlds_scape_Surface_addPolygon@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Surface_addPolygon_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
                    /* 0x203c0  299  _Java_NET_worlds_scape_Surface_addPolygon@12 */
  iVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049ff58);
  if (iVar1 == 0) {
    FUN_00402800(s_nSurface_00471244,0x59);
  }
  iVar2 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar1);
  uVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049ff34);
  iVar4 = FUN_00416fd0(param_1,uVar3);
  if (iVar4 == 0) {
    FUN_00402800(s_nSurface_00471244,0x5f);
  }
  iVar4 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar4);
  if (iVar2 != iVar4) {
    FUN_00402800(s_nSurface_00471244,0x60);
  }
  piVar5 = (int *)(**(code **)(*param_1 + 0x2ec))(param_1,iVar1,0);
  if (*piVar5 != 0) {
    FUN_00402a50(param_1,s_Surface_already_has_its_poly_set_00471288);
    return;
  }
  uVar6 = (**(code **)(*param_1 + 0x2ec))(param_1,param_3,0);
  uVar7 = (**(code **)(*param_1 + 0x2ac))(param_1,param_3);
  uVar3 = uVar6;
  uVar8 = FUN_00412cf0(param_1,param_2);
  iVar2 = FUN_00418e30(uVar8,uVar7,uVar3);
  *piVar5 = iVar2;
  (**(code **)(*param_1 + 0x30c))(param_1,iVar1,piVar5,0);
  (**(code **)(*param_1 + 0x30c))(param_1,param_3,uVar6,0);
  return;
}


