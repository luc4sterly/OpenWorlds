// 0041e440 _Java_NET_worlds_scape_ShapeLoader_loadBodFile@16 [Global]
// programa: gamma.dll

int _Java_NET_worlds_scape_ShapeLoader_loadBodFile_16
              (int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int local_1c;
  uint local_14;
  
                    /* 0x1e440  287  _Java_NET_worlds_scape_ShapeLoader_loadBodFile@16 */
  pbVar6 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  local_14 = 0;
  local_1c = 0;
  pbVar7 = FUN_0041e2f0(param_1,pbVar6,&local_14);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar6);
  if (((pbVar7 == (byte *)0x0) || (1 < *pbVar7)) || (pbVar7[1] == 0)) {
    local_1c = FUN_00418f90();
    if (local_1c == 0) {
      FUN_00402800(s_nShape_00470970,0x46c);
    }
  }
  else {
    iVar2 = (uint)pbVar7[1] * 3;
    iVar1 = iVar2 + 2;
    uVar10 = 0;
    uVar4 = local_14 - iVar1;
    do {
      iVar3 = iVar2 + -3;
      uVar9 = uVar4;
      if (iVar3 < 0) break;
      uVar9 = (uint)CONCAT11(pbVar7[iVar2 + 1],pbVar7[iVar2]);
      iVar5 = iVar2 + -1;
      uVar10 = uVar4;
      uVar4 = uVar9;
      iVar2 = iVar3;
    } while (param_4 != pbVar7[iVar5]);
    if ((-1 < iVar3) && ((int)(iVar1 + uVar10) <= (int)local_14)) {
      local_1c = FUN_0041e240((uint)*pbVar7,(uint)(pbVar7 + uVar9 + iVar1),uVar10 - uVar9);
    }
    if (local_1c != 0) {
      uVar8 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489660);
      (**(code **)(*param_1 + 0x1b4))(param_1,uVar8,DAT_00489664,local_1c);
      return local_1c;
    }
    local_1c = FUN_00418f90();
    if (local_1c == 0) {
      FUN_00402800(s_nShape_00470970,0x48f);
    }
  }
  FUN_00419d60(local_1c,0);
  return local_1c;
}


