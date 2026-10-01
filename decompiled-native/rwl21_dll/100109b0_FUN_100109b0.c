// 100109b0 FUN_100109b0 [Global]
// program: RWL21.DLL

bool FUN_100109b0(FILE *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  bool bVar8;
  int local_28 [3];
  char local_1c [28];
  
  iVar2 = FUN_10020800(param_1,s__d_d_d_1005aac4);
  if (iVar2 != 3) {
    FUN_1000cba0(5);
    return false;
  }
  do {
    iVar2 = FUN_100206d0(param_1,local_1c,0x18);
    if ((iVar2 == 0) || (local_1c[0] == '#')) {
      piVar4 = FUN_100037e0(**(uint **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),3,local_28);
      puVar6 = (undefined4 *)0x0;
      if (piVar4 != (int *)0x0) {
        piVar5 = (int *)RwCurrentMaterial();
        puVar6 = RwSetPolygonMaterial(piVar4,piVar5);
        if (puVar6 != (undefined4 *)0x0) {
          RwSetPolygonTag((int)puVar6,0);
        }
      }
      return (bool)('\x01' - (puVar6 == (undefined4 *)0x0));
    }
    pcVar3 = local_1c;
    cVar1 = local_1c[0];
    while (bVar8 = cVar1 == '\0', !bVar8) {
      cVar1 = *pcVar3;
      if (('@' < cVar1) && (cVar1 < '[')) {
        *pcVar3 = cVar1 + ' ';
      }
      pcVar7 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar7;
    }
    iVar2 = 4;
    pcVar3 = local_1c;
    pcVar7 = &DAT_1005aac0;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar8 = *pcVar3 == *pcVar7;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (!bVar8) {
      FUN_1000cba0(4);
      return false;
    }
    iVar2 = FUN_10020800(param_1,&DAT_1005aabc);
    if (iVar2 != 1) {
      FUN_1000cba0(5);
      return false;
    }
  } while( true );
}


