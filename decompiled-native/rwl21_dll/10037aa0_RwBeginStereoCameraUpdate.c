// 10037aa0 RwBeginStereoCameraUpdate [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall RwBeginStereoCameraUpdate(int param_1,int *param_2,int param_3,HWND param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_EDX;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  longlong lVar7;
  tagPOINT local_8;
  
                    /* 0x37aa0  20  RwBeginStereoCameraUpdate */
  if ((param_3 != 0) && (iVar4 = 0, puVar1 = DAT_1005b748, 0 < DAT_1005b744)) {
    do {
      param_2 = (int *)*puVar1;
      param_1 = param_3;
      if (*param_2 == param_3) {
        piVar3 = (int *)DAT_1005b748[iVar4];
        goto LAB_10037ad8;
      }
      iVar4 = iVar4 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar4 < DAT_1005b744);
  }
  piVar3 = (int *)0x0;
LAB_10037ad8:
  if (piVar3 != (int *)0x0) {
    DAT_1005b740 = param_4;
    DAT_1005b73c = piVar3;
    if (piVar3[0x11b] == 1) {
      RwBeginCameraUpdate(param_3,param_4);
      return param_3;
    }
    puVar1 = (undefined4 *)RwPushScratchMatrix(param_1,(int)param_2);
    if (puVar1 != (undefined4 *)0x0) {
      local_8.x = 0;
      local_8.y = *(int *)(*piVar3 + 0x58);
      ClientToScreen(param_4,&local_8);
      iVar4 = piVar3[0x11b];
      iVar2 = extraout_EDX;
      if (iVar4 != 1) {
        if ((local_8.y - 1U & 1) != 0) {
          if (iVar4 == 2) {
            iVar4 = 3;
          }
          else if (iVar4 == 3) {
            iVar4 = 2;
          }
        }
        puVar5 = (undefined1 *)*piVar3;
        puVar6 = (undefined1 *)piVar3[0x8f];
        for (iVar2 = 0x22c; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        puVar5 = (undefined1 *)*piVar3;
        puVar6 = (undefined1 *)piVar3[3];
        for (iVar2 = 0x22c; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        *(int *)piVar3[0x8f] = piVar3[0x90];
        *(int *)piVar3[3] = piVar3[4];
        *(int *)(piVar3[0x8f] + 0x100) = piVar3[0xd0];
        *(int *)(piVar3[3] + 0x100) = piVar3[0x44];
        *(int *)(piVar3[0x8f] + 0x10c) = piVar3[0xd3];
        *(int *)(piVar3[3] + 0x10c) = piVar3[0x47];
        *(int *)(piVar3[0x8f] + 0x220) = piVar3[0x118];
        *(int *)(piVar3[3] + 0x220) = piVar3[0x8c];
        *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x1c) =
             *(undefined4 *)(*(int *)(*piVar3 + 0x100) + 0x1c);
        *(undefined4 *)(*(int *)(piVar3[0x8f] + 0x100) + 0x1c) =
             *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x1c);
        *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x20) =
             *(undefined4 *)(*(int *)(*piVar3 + 0x100) + 0x20);
        *(undefined4 *)(*(int *)(piVar3[0x8f] + 0x100) + 0x20) =
             *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x20);
        *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x24) =
             *(undefined4 *)(*(int *)(*piVar3 + 0x100) + 0x24);
        *(undefined4 *)(*(int *)(piVar3[0x8f] + 0x100) + 0x24) =
             *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x24);
        *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x28) =
             *(undefined4 *)(*(int *)(*piVar3 + 0x100) + 0x28);
        *(undefined4 *)(*(int *)(piVar3[0x8f] + 0x100) + 0x28) =
             *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x28);
        *(undefined4 *)(*(int *)(piVar3[3] + 0x100) + 0x18) =
             *(undefined4 *)(*(int *)(*piVar3 + 0x100) + 0x18);
        iVar2 = *(int *)(*(int *)(piVar3[3] + 0x100) + 0x18);
        *(int *)(*(int *)(piVar3[0x8f] + 0x100) + 0x18) = iVar2;
        switch(iVar4) {
        case 2:
        case 3:
          *(int *)(piVar3[3] + 0x58) = *(int *)(*piVar3 + 0x58) >> 1;
          *(undefined4 *)(piVar3[0x8f] + 0x58) = *(undefined4 *)(piVar3[3] + 0x58);
          *(int *)(piVar3[3] + 0x60) = *(int *)(*piVar3 + 0x60) >> 1;
          *(undefined4 *)(piVar3[0x8f] + 0x60) = *(undefined4 *)(piVar3[3] + 0x60);
          lVar7 = __ftol();
          *(float *)(piVar3[3] + 0x70) = (float)(int)lVar7 * _DAT_10052290;
          *(undefined4 *)(piVar3[0x8f] + 0x70) = *(undefined4 *)(piVar3[3] + 0x70);
          *(int *)(*(int *)(piVar3[3] + 0x100) + 0x20) =
               *(int *)(*(int *)(*piVar3 + 0x100) + 0x20) >> 1;
          iVar2 = *(int *)(piVar3[3] + 0x100);
          *(undefined4 *)(*(int *)(piVar3[0x8f] + 0x100) + 0x20) = *(undefined4 *)(iVar2 + 0x20);
          *(uint *)(piVar3[0x8f] + 0x228) = *(uint *)(piVar3[0x8f] + 0x228) | 6;
          *(uint *)(piVar3[3] + 0x228) = *(uint *)(piVar3[3] + 0x228) | 6;
          if (iVar4 == 2) {
            *(int *)(piVar3[3] + 0x58) = *(int *)(piVar3[3] + 0x58) + 1;
            *(int *)(piVar3[3] + 0x68) = *(int *)(piVar3[3] + 0x68) + 1;
          }
          else {
            *(int *)(piVar3[0x8f] + 0x58) = *(int *)(piVar3[0x8f] + 0x58) + 1;
            *(int *)(piVar3[0x8f] + 0x68) = *(int *)(piVar3[0x8f] + 0x68) + 1;
          }
          break;
        case 4:
        case 5:
          *(float *)(piVar3[3] + 0x90) = *(float *)(*piVar3 + 0x90) * _DAT_10052294;
          *(undefined4 *)(piVar3[0x8f] + 0x90) = *(undefined4 *)(piVar3[3] + 0x90);
          *(int *)(piVar3[3] + 0x54) = *(int *)(*piVar3 + 0x54) >> 1;
          *(undefined4 *)(piVar3[0x8f] + 0x54) = *(undefined4 *)(piVar3[3] + 0x54);
          *(int *)(piVar3[3] + 0x5c) = *(int *)(*piVar3 + 0x5c) >> 1;
          *(undefined4 *)(piVar3[0x8f] + 0x5c) = *(undefined4 *)(piVar3[3] + 0x5c);
          lVar7 = __ftol();
          *(float *)(piVar3[3] + 0x6c) = (float)(int)lVar7 * _DAT_10052290;
          *(undefined4 *)(piVar3[0x8f] + 0x6c) = *(undefined4 *)(piVar3[3] + 0x6c);
          *(int *)(piVar3[3] + 0xac) = *(int *)(*piVar3 + 0xac) >> 1;
          *(undefined4 *)(piVar3[0x8f] + 0xac) = *(undefined4 *)(piVar3[3] + 0xac);
          *(uint *)(piVar3[3] + 0x228) = *(uint *)(piVar3[3] + 0x228) | 2;
          *(uint *)(piVar3[0x8f] + 0x228) = *(uint *)(piVar3[0x8f] + 0x228) | 2;
          if (iVar4 == 4) {
            iVar4 = piVar3[3];
            iVar2 = *(int *)(iVar4 + 0x54) + *(int *)(iVar4 + 0x5c);
            *(int *)(iVar4 + 0x54) = iVar2;
            iVar4 = piVar3[3];
          }
          else {
            iVar4 = piVar3[0x8f];
            iVar2 = *(int *)(iVar4 + 0x54) + *(int *)(iVar4 + 0x5c);
            *(int *)(iVar4 + 0x54) = iVar2;
            iVar4 = piVar3[0x8f];
          }
          *(int *)(iVar4 + 100) = *(int *)(iVar4 + 100) + *(int *)(iVar4 + 0x5c);
        }
      }
      RwGetCameraLTM(*piVar3,iVar2,*piVar3,puVar1);
      RwTransformCamera(puVar1,piVar3[0x8f],piVar3[0x8f],(float *)puVar1,1);
      RwTransformCamera(puVar1,piVar3[3],piVar3[3],(float *)puVar1,1);
      local_8.x = (LONG)((float)piVar3[1] / (float)piVar3[2]);
      RwVCMoveCamera(piVar3[0x8f],(float)piVar3[1] - (float)local_8.x,0.0,0.0);
      RwSetCameraViewOffset(piVar3[0x8f],local_8.x,0);
      RwVCMoveCamera(piVar3[3],-((float)piVar3[1] - (float)local_8.x),0.0,0.0);
      RwSetCameraViewOffset(piVar3[3],-(float)local_8.x,0);
      RwPopScratchMatrix();
      return param_3;
    }
  }
  return 0;
}


