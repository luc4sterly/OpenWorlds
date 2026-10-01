// 10035b10 FUN_10035b10 [Global]
// program: RWL21.DLL

undefined4 * FUN_10035b10(undefined4 *param_1,int *param_2)

{
  FILE *_File;
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  puVar1 = (uint *)RwCurrentMaterial();
  puVar2 = (uint *)RwGetPolygonMaterial(param_1);
  iVar3 = FUN_10034e20((FILE *)param_2[1],*param_2,puVar2,puVar1);
  if (iVar3 == 0) {
    return (undefined4 *)0x0;
  }
  if (*(byte *)((int)param_1 + 0x3a) < 3) {
    FUN_1000cba0(0x29);
    return (undefined4 *)0x0;
  }
  _File = (FILE *)param_2[1];
  for (iVar3 = *param_2; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar4 = _fputc(0x20,_File);
    if (iVar4 == -1) {
      FUN_1000cba0(6);
      return (undefined4 *)0x0;
    }
  }
  uVar5 = (uint)*(byte *)((int)param_1 + 0x3a);
  if (uVar5 == 3) {
    if (*(short *)(param_1 + 0xe) == 0) {
      iVar3 = _fprintf((FILE *)param_2[1],s_Triangle_1005b2f8);
      if (iVar3 == -1) {
        FUN_1000cba0(6);
        return (undefined4 *)0x0;
      }
    }
    else {
      iVar3 = _fprintf((FILE *)param_2[1],s_TriangleExt_1005b304);
      if (iVar3 == -1) {
        FUN_1000cba0(6);
        return (undefined4 *)0x0;
      }
    }
  }
  else if (uVar5 == 4) {
    if (*(short *)(param_1 + 0xe) == 0) {
      iVar3 = _fprintf((FILE *)param_2[1],&DAT_1005b2e8);
      if (iVar3 == -1) {
        FUN_1000cba0(6);
        return (undefined4 *)0x0;
      }
    }
    else {
      iVar3 = _fprintf((FILE *)param_2[1],s_QuadExt_1005b2f0);
      if (iVar3 == -1) {
        FUN_1000cba0(6);
        return (undefined4 *)0x0;
      }
    }
  }
  else if (*(short *)(param_1 + 0xe) == 0) {
    iVar3 = _fprintf((FILE *)param_2[1],s_Polygon__d_1005b2cc,uVar5);
    if (iVar3 == -1) {
      FUN_1000cba0(6);
      return (undefined4 *)0x0;
    }
  }
  else {
    iVar3 = _fprintf((FILE *)param_2[1],s_PolygonExt__d_1005b2d8,uVar5);
    if (iVar3 == -1) {
      FUN_1000cba0(6);
      return (undefined4 *)0x0;
    }
  }
  iVar3 = 0;
  if (*(char *)((int)param_1 + 0x3a) != '\0') {
    piVar6 = param_1 + 0xf;
    do {
      iVar4 = FUN_10041c70(*(int *)(param_1[0xd] + 0x88),*piVar6);
      iVar4 = _fprintf((FILE *)param_2[1],&DAT_1005b2c8,iVar4);
      if (iVar4 == -1) {
        FUN_1000cba0(6);
        return (undefined4 *)0x0;
      }
      piVar6 = piVar6 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
  }
  if ((*(short *)(param_1 + 0xe) != 0) &&
     (iVar3 = _fprintf((FILE *)param_2[1],s_Tag__d_1005b2c0,(int)*(short *)(param_1 + 0xe)),
     iVar3 == -1)) {
    FUN_1000cba0(6);
    return (undefined4 *)0x0;
  }
  iVar3 = _fputc(10,(FILE *)param_2[1]);
  if (iVar3 == -1) {
    FUN_1000cba0(6);
    return (undefined4 *)0x0;
  }
  return param_1;
}


