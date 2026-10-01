// 10004ee0 FUN_10004ee0 [Global]
// program: RWL21.DLL

undefined4 * FUN_10004ee0(undefined4 *param_1,uint param_2)

{
  undefined1 uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  undefined3 extraout_var_00;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int local_400 [256];
  
  if (param_2 == 0) {
    FUN_1000cba0(1);
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_2 + 0xb0);
  }
  iVar7 = *piVar4;
  uVar1 = RwGetPolygonVertices((int)param_1,local_400);
  iVar3 = CONCAT31(extraout_var,uVar1) + -1;
  if (-1 < iVar3) {
    piVar4 = local_400 + iVar3;
    do {
      piVar5 = piVar4 + -1;
      *piVar4 = *piVar4 + iVar7 + -1;
      piVar4 = piVar5;
    } while (local_400 <= piVar5);
  }
  piVar4 = FUN_10001220((uint)*(byte *)((int)param_1 + 0x3a),*(int *)(param_2 + 0x88),local_400);
  if (piVar4 != (int *)0x0) {
    bVar2 = FUN_10003660(param_2,piVar4);
    if (CONCAT31(extraout_var_00,bVar2) == 0) {
      RwDestroyPolygon(piVar4);
      piVar4 = (int *)0x0;
    }
    if (piVar4 != (int *)0x0) {
      piVar5 = (int *)RwGetPolygonMaterial(param_1);
      RwSetPolygonMaterial(piVar4,piVar5);
      uVar6 = RwGetPolygonData((int)param_1);
      RwSetPolygonData((int)piVar4,uVar6);
      iVar7 = RwGetPolygonTag((int)param_1);
      RwSetPolygonTag((int)piVar4,(short)iVar7);
      return param_1;
    }
  }
  return (undefined4 *)0x0;
}


