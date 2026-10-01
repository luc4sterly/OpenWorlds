// 100079d0 RwRenderImmediateTriangle [Global]
// program: RWL21.DLL

void __fastcall RwRenderImmediateTriangle(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  undefined *puVar5;
  int *piVar6;
  uint uVar7;
  byte bVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar9;
  code *pcVar10;
  int *piVar11;
  undefined8 uVar12;
  
                    /* 0x79d0  348  RwRenderImmediateTriangle */
  puVar5 = PTR_DAT_1005b69c;
  piVar6 = (int *)param_3[0x59];
  piVar11 = (int *)(PTR_DAT_1005b69c + 0x2f0);
  piVar2 = param_3 + 0x59;
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)RwCurrentMaterial();
    *piVar2 = (int)piVar6;
    param_2 = extraout_EDX;
  }
  iVar4 = *param_3;
  if (iVar4 == 0) {
    piVar1 = param_3 + 2;
    param_3[0x68] = (int)piVar1;
    param_3[0x69] = (int)(param_3 + 0x1f);
    param_3[0x6a] = (int)(param_3 + 0x3c);
    if ((*(int *)(puVar5 + 0x348) == 0) || (param_3[1] == 0)) {
      pcVar10 = *(code **)(PTR_DAT_1005b69c + *piVar6 * 4 + 0x54);
    }
    else {
      pcVar10 = *(code **)(PTR_DAT_1005b69c + *piVar6 * 4 + 0x154);
    }
    if (*piVar11 == 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x294))
                (piVar1,3,*(undefined4 *)(puVar5 + 0x340),*(undefined4 *)(PTR_DAT_1005b69c + 0x10),1
                );
      uVar12 = FUN_10051000(extraout_ECX_00,extraout_EDX_00,(int)piVar2);
      uVar7 = -(uint)((int)uVar12 == 0) & 0x10000;
      if ((uVar7 == 0) || ((*(byte *)(*piVar2 + 0x30) & 0x80) != 0)) {
        (*pcVar10)(piVar2,uVar7);
        return;
      }
    }
    else {
      (**(code **)(PTR_DAT_1005b69c + 0x294))
                (piVar1,3,*(undefined4 *)(puVar5 + 0x340),*(undefined4 *)(PTR_DAT_1005b69c + 0x10),2
                );
      bVar3 = *(byte *)(param_3[0x69] + 0x48);
      bVar8 = *(byte *)(param_3[0x68] + 0x48) & bVar3 & *(byte *)(param_3[0x6a] + 0x48);
      if ((bVar8 & 0x3f) == 0) {
        if (((*(byte *)(param_3[0x6a] + 0x48) | bVar3 | *(byte *)(param_3[0x68] + 0x48)) & 0x3f) !=
            0) {
          DAT_1005ad20 = pcVar10;
          (**(code **)(puVar5 + 0x2f4))(piVar2);
          return;
        }
        uVar12 = FUN_10051000(CONCAT31((int3)((uint)extraout_ECX >> 8),bVar3),
                              CONCAT31((int3)((uint)param_3[0x69] >> 8),bVar8),(int)piVar2);
        uVar7 = -(uint)((int)uVar12 == 0) & 0x10000;
        if ((uVar7 == 0) || ((*(byte *)(*piVar2 + 0x30) & 0x80) != 0)) {
          (*pcVar10)(piVar2,uVar7);
          return;
        }
      }
    }
  }
  else if (iVar4 == 1) {
    if ((*(int *)(puVar5 + 0x348) == 0) || (param_3[1] == 0)) {
      pcVar10 = *(code **)(PTR_DAT_1005b69c + *piVar6 * 4 + 0x54);
    }
    else {
      pcVar10 = *(code **)(PTR_DAT_1005b69c + *piVar6 * 4 + 0x154);
    }
    param_3[0x68] = (int)(param_3 + 2);
    param_3[0x69] = (int)(param_3 + 0x1f);
    param_3[0x6a] = (int)(param_3 + 0x3c);
    *(undefined1 *)(param_3[0x68] + 0x48) = 0;
    iVar4 = param_3[0x69];
    *(undefined1 *)(iVar4 + 0x48) = 0;
    *(undefined1 *)(param_3[0x6a] + 0x48) = 0;
    uVar12 = FUN_10051000(iVar4,param_2,(int)piVar2);
    uVar7 = -(uint)((int)uVar12 == 0) & 0x10000;
    if ((uVar7 == 0) || ((*(byte *)(*piVar2 + 0x30) & 0x80) != 0)) {
      (*pcVar10)(piVar2,uVar7);
      return;
    }
  }
  else {
    if (iVar4 != 2) {
      return;
    }
    iVar4 = *(int *)(*(int *)(puVar5 + 0x33c) + 0x88);
    iVar9 = iVar4 + 0xc;
    param_3[0x68] = iVar9 + param_3[0x1d] * 0x74 + 0x32c;
    param_3[0x69] = iVar9 + param_3[0x3a] * 0x74 + 0x32c;
    iVar4 = iVar4 + 0x338 + param_3[0x57] * 0x74;
    param_3[0x6a] = iVar4;
    if ((*(int *)(puVar5 + 0x348) == 0) || (param_3[1] == 0)) {
      pcVar10 = *(code **)(PTR_DAT_1005b69c + *piVar6 * 4 + 0x54);
    }
    else {
      pcVar10 = *(code **)(PTR_DAT_1005b69c + *piVar6 * 4 + 0x154);
    }
    if (*piVar11 == 0) {
      uVar12 = FUN_10051000(iVar4,PTR_DAT_1005b69c,(int)piVar2);
      uVar7 = -(uint)((int)uVar12 == 0) & 0x10000;
      if ((uVar7 == 0) || ((*(byte *)(*piVar2 + 0x30) & 0x80) != 0)) {
        (*pcVar10)(piVar2,uVar7);
      }
    }
    else {
      bVar3 = *(byte *)(param_3[0x69] + 0x48);
      bVar8 = *(byte *)(param_3[0x68] + 0x48) & bVar3 & *(byte *)(iVar4 + 0x48);
      if ((bVar8 & 0x3f) == 0) {
        if (((*(byte *)(iVar4 + 0x48) | bVar3 | *(byte *)(param_3[0x68] + 0x48)) & 0x3f) != 0) {
          DAT_1005ad20 = pcVar10;
          (**(code **)(puVar5 + 0x2f4))(piVar2);
          return;
        }
        uVar12 = FUN_10051000(CONCAT31((int3)((uint)iVar4 >> 8),bVar8),
                              CONCAT31((int3)((uint)PTR_DAT_1005b69c >> 8),bVar3),(int)piVar2);
        uVar7 = -(uint)((int)uVar12 == 0) & 0x10000;
        if ((uVar7 == 0) || ((*(byte *)(*piVar2 + 0x30) & 0x80) != 0)) {
          (*pcVar10)(piVar2,uVar7);
          return;
        }
      }
    }
  }
  return;
}


