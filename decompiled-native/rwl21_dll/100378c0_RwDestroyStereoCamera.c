// 100378c0 RwDestroyStereoCamera [Global]
// program: RWL21.DLL

undefined4 RwDestroyStereoCamera(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
                    /* 0x378c0  67  RwDestroyStereoCamera */
  if ((param_1 != 0) && (iVar3 = 0, puVar2 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      if (*(int *)*puVar2 == param_1) {
        puVar2 = (undefined4 *)DAT_1005b748[iVar3];
        goto LAB_100378f0;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < DAT_1005b744);
  }
  puVar2 = (undefined4 *)0x0;
LAB_100378f0:
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1 = puVar2 + 0x90;
  puVar5 = (undefined4 *)puVar2[0x8f];
  for (iVar3 = 0x8b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar1 = puVar2 + 4;
  puVar5 = (undefined4 *)puVar2[3];
  for (iVar3 = 0x8b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar5 = puVar5 + 1;
  }
  RwDestroyCamera((undefined4 *)puVar2[3]);
  RwDestroyCamera((undefined4 *)puVar2[0x8f]);
  RwDestroyCamera((undefined4 *)*puVar2);
  iVar3 = 0;
  puVar1 = DAT_1005b748;
  if (0 < DAT_1005b744) {
    do {
      if ((undefined4 *)*puVar1 == puVar2) {
        if (iVar3 < DAT_1005b744 + -1) {
          iVar4 = iVar3 * 4;
          do {
            iVar3 = iVar3 + 1;
            puVar1 = (undefined4 *)((int)DAT_1005b748 + iVar4);
            iVar4 = iVar4 + 4;
            *puVar1 = puVar1[1];
          } while (iVar3 < DAT_1005b744 + -1);
        }
        if (DAT_1005b744 < 2) {
          DAT_1005b748 = (undefined4 *)0x0;
          DAT_1005b744 = 0;
        }
        else {
          DAT_1005b744 = DAT_1005b744 + -1;
          DAT_1005b748 = (undefined4 *)
                         (**(code **)(PTR_DAT_1005b69c + 0x354))(DAT_1005b748,DAT_1005b744 * 4);
        }
        break;
      }
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar3 < DAT_1005b744);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar2);
  return 1;
}


