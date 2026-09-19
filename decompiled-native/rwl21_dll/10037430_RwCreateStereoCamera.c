// 10037430 RwCreateStereoCamera [Global]
// programa: RWL21.DLL

int RwCreateStereoCamera(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
                    /* 0x37430  47  RwCreateStereoCamera */
  piVar2 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(0x470);
  if (piVar2 != (int *)0x0) {
    puVar3 = RwCreateCamera(param_1,param_2,param_3);
    *piVar2 = (int)puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      piVar4 = RwCreateCamera(1,param_2,(undefined4 *)0x0);
      piVar2[0x8f] = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        piVar6 = piVar2 + 0x90;
        for (iVar5 = 0x8b; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar6 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar6 = piVar6 + 1;
        }
        piVar4 = RwCreateCamera(1,param_2,(undefined4 *)0x0);
        piVar2[3] = (int)piVar4;
        if (piVar4 != (int *)0x0) {
          piVar6 = piVar2 + 4;
          for (iVar5 = 0x8b; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar6 = *piVar4;
            piVar4 = piVar4 + 1;
            piVar6 = piVar6 + 1;
          }
          piVar2[0x11b] = 1;
          if (DAT_1005b744 == 0) {
            DAT_1005b748 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(4);
            if (DAT_1005b748 == (int *)0x0) {
              bVar1 = false;
            }
            else {
              *DAT_1005b748 = (int)piVar2;
              bVar1 = true;
              DAT_1005b744 = 1;
            }
          }
          else {
            iVar5 = 0;
            piVar4 = DAT_1005b748;
            if (0 < DAT_1005b744) {
              do {
                if (*piVar4 == 0) {
                  DAT_1005b748[iVar5] = (int)piVar2;
                  goto LAB_1003756e;
                }
                iVar5 = iVar5 + 1;
                piVar4 = piVar4 + 1;
              } while (iVar5 < DAT_1005b744);
            }
            piVar4 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x354))
                                      (DAT_1005b748,DAT_1005b744 * 4 + 4);
            if (piVar4 == (int *)0x0) {
              bVar1 = false;
            }
            else {
              DAT_1005b748 = piVar4;
              piVar4[DAT_1005b744] = (int)piVar2;
              DAT_1005b744 = DAT_1005b744 + 1;
LAB_1003756e:
              bVar1 = true;
            }
          }
          if (bVar1) {
            if ((*piVar2 != 0) && (iVar5 = 0, piVar4 = DAT_1005b748, 0 < DAT_1005b744)) {
              do {
                if (*(int *)*piVar4 == *piVar2) {
                  iVar5 = DAT_1005b748[iVar5];
                  goto LAB_100375a7;
                }
                iVar5 = iVar5 + 1;
                piVar4 = piVar4 + 1;
              } while (iVar5 < DAT_1005b744);
            }
            iVar5 = 0;
LAB_100375a7:
            if (iVar5 != 0) {
              *(undefined4 *)(iVar5 + 4) = 0x3d23d70a;
            }
            if ((*piVar2 != 0) && (iVar5 = 0, piVar4 = DAT_1005b748, 0 < DAT_1005b744)) {
              do {
                if (*(int *)*piVar4 == *piVar2) {
                  iVar5 = DAT_1005b748[iVar5];
                  goto LAB_100375dc;
                }
                iVar5 = iVar5 + 1;
                piVar4 = piVar4 + 1;
              } while (iVar5 < DAT_1005b744);
            }
            iVar5 = 0;
LAB_100375dc:
            if (iVar5 != 0) {
              *(undefined4 *)(iVar5 + 8) = 0x41200000;
            }
            return *piVar2;
          }
          RwDestroyCamera((undefined4 *)piVar2[3]);
        }
        RwDestroyCamera((undefined4 *)piVar2[0x8f]);
      }
      RwDestroyCamera((undefined4 *)*piVar2);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar2);
  }
  return 0;
}


