// 100016c0 RwGetPolygonVertices [Global]
// program: RWL21.DLL

undefined1 RwGetPolygonVertices(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
                    /* 0x16c0  231  RwGetPolygonVertices */
  if (param_1 != 0) {
    iVar4 = 0;
    iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x88);
    if (*(char *)(param_1 + 0x3a) != '\0') {
      piVar3 = (int *)(param_1 + 0x3c);
      do {
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
        iVar4 = iVar4 + 1;
        iVar2 = FUN_10041c70(iVar1,iVar2);
        *param_2 = iVar2;
        param_2 = param_2 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x3a));
    }
    return *(undefined1 *)(param_1 + 0x3a);
  }
  FUN_1000cba0(1);
  return 0;
}


