// 1003d6b0 RwGetChunkSize [Global]
// programa: RWL21.DLL

int RwGetChunkSize(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int *local_8;
  int local_4;
  
                    /* 0x3d6b0  145  RwGetChunkSize */
  if (param_1 < 0x43414d46) {
    if (param_1 == 0x43414d45) {
      if (((param_3 & 8) == 0) || ((int *)param_2[0x28] == (int *)0x0)) {
        iVar5 = 0;
      }
      else {
        iVar5 = RwGetChunkSize(0x52415354,(int *)param_2[0x28],param_3);
      }
      iVar1 = RwGetChunkSize(0x4d415458,param_2,0);
      iVar2 = RwGetChunkSize(0x56334420,param_2,0);
      iVar3 = RwGetChunkSize(0x53545254,param_2,0x5c);
      return iVar1 + iVar2 + iVar3 + 8 + iVar5;
    }
    if (param_1 != 0x41544f4d) {
      return 0;
    }
    iVar1 = RwGetChunkSize(0x504c5354,param_2,param_3);
    iVar2 = RwGetChunkSize(0x564c5354,param_2,param_3);
    iVar3 = RwGetChunkSize(0x53545254,(int *)0x0,0x34);
    iVar4 = RwGetChunkSize(0x4d415458,(int *)0x0,0);
    iVar5 = RwGetChunkSize(0x4d415458,(int *)0x0,0);
    iVar5 = iVar1 + iVar2 + iVar3 + iVar4 + 8 + iVar5;
    for (piVar6 = (int *)RwGetFirstChildClump((int)param_2); piVar6 != (int *)0x0;
        piVar6 = (int *)RwGetNextClump((int)piVar6)) {
      iVar1 = RwGetChunkSize(0x41544f4d,piVar6,param_3);
      iVar5 = iVar5 + iVar1;
    }
    return iVar5;
  }
  if (0x44415441 < param_1) {
    if (param_1 < 0x4d414c55) {
      if (param_1 == 0x4d414c54) {
        iVar5 = *(int *)(DAT_1005b798[2] + 8);
        iVar1 = RwGetChunkSize(0x53545254,(int *)0x0,0xc);
        return iVar1 + 8 + iVar5 * 0x28;
      }
      if (param_1 != 0x4c495445) {
        return 0;
      }
      iVar5 = RwGetChunkSize(0x53545254,param_2,0x38);
      iVar1 = RwGetChunkSize(0x4d415458,param_2 + 2,0);
      return iVar5 + 8 + iVar1;
    }
    if (param_1 < 0x4d415459) {
      if (param_1 == 0x4d415458) {
        iVar5 = RwGetChunkSize(0x53545254,param_2,0x40);
        return iVar5 + 8;
      }
      if (param_1 != 0x4d415452) {
        return 0;
      }
      iVar5 = RwGetMaterialTexture((int)param_2);
      if (iVar5 != 0) {
        piVar6 = (int *)RwGetMaterialTexture((int)param_2);
        iVar5 = RwGetChunkSize(0x54455855,piVar6,param_3);
        iVar1 = RwGetChunkSize(0x53545254,param_2,0x28);
        return iVar5 + 8 + iVar1;
      }
      iVar5 = RwGetChunkSize(0x53545254,param_2,0x28);
      return iVar5 + 8;
    }
    if (param_1 < 0x504c5355) {
      if (param_1 != 0x504c5354) {
        if (param_1 != 0x50414c4c) {
          return 0;
        }
        return 0x408;
      }
      piVar6 = (int *)param_2[0x26];
      iVar5 = RwGetChunkSize(0x53545254,(int *)0x0,0xc);
      iVar5 = iVar5 + 8;
      iVar1 = *piVar6;
      if (iVar1 != 0) {
        piVar6 = piVar6 + 2;
        do {
          iVar2 = *piVar6;
          piVar6 = piVar6 + 1;
          iVar5 = iVar5 + ((int)(param_3 << 0x1d) >> 0x1f & 0xcU) + 8 +
                          (uint)*(byte *)(iVar2 + 0x3a) * 4 +
                          ((int)(param_3 << 0x1f) >> 0x1f & 0xcU) + ((param_3 & 0x10) >> 2);
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        return iVar5;
      }
    }
    else {
      if (param_1 < 0x52415355) {
        if (param_1 == 0x52415354) {
          iVar5 = RwGetRasterHeight((int)param_2);
          local_4 = RwGetRasterStride((int)param_2);
          local_4 = iVar5 * local_4;
          iVar5 = RwGetChunkSize(0x44415441,(int *)&local_8,param_3);
          iVar1 = RwGetChunkSize(0x53545254,param_2,0x28);
          return iVar5 + 8 + iVar1;
        }
        if (param_1 != 0x52414c54) {
          return 0;
        }
        uVar9 = *(uint *)(*DAT_1005b798 + 8);
        iVar5 = RwGetChunkSize(0x53545254,(int *)0x0,0xc);
        iVar5 = iVar5 + 8;
        if (((param_3 & 8) != 0) && (uVar8 = 1, uVar9 != 0)) {
          do {
            if (((uint)((int *)*DAT_1005b798)[2] < uVar8) || (uVar8 == 0)) {
              piVar6 = (int *)0x0;
            }
            else {
              piVar6 = *(int **)(*(int *)*DAT_1005b798 + -4 + uVar8 * 4);
            }
            uVar8 = uVar8 + 1;
            iVar1 = RwGetChunkSize(0x52415354,piVar6,param_3);
            iVar5 = iVar5 + iVar1;
          } while (uVar8 <= uVar9);
        }
        return iVar5;
      }
      if (param_1 < 0x5343454f) {
        if (param_1 != 0x5343454e) {
          if (param_1 != 0x52454354) {
            return 0;
          }
          iVar5 = RwGetChunkSize(0x53545254,param_2,0x10);
          return iVar5 + 8;
        }
        bVar10 = DAT_1005b798 == (int *)0x0;
        if (bVar10) {
          DAT_1005b798 = FUN_10037030(DAT_1005b794);
          if (DAT_1005b798 != (int *)0x0) {
            piVar6 = FUN_10037030(DAT_1005b790);
            if (piVar6 != (int *)0x0) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
              *piVar6 = iVar5;
              if (iVar5 == 0) {
                if (piVar6 != (int *)0x0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                  FUN_10037010(DAT_1005b790,piVar6);
                }
                piVar6 = (int *)0x0;
              }
              else {
                piVar6[2] = 0;
                piVar6[1] = 10;
              }
            }
            *DAT_1005b798 = (int)piVar6;
            piVar6 = FUN_10037030(DAT_1005b790);
            if (piVar6 != (int *)0x0) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
              *piVar6 = iVar5;
              if (iVar5 == 0) {
                if (piVar6 != (int *)0x0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                  FUN_10037010(DAT_1005b790,piVar6);
                }
                piVar6 = (int *)0x0;
              }
              else {
                piVar6[2] = 0;
                piVar6[1] = 10;
              }
            }
            DAT_1005b798[1] = (int)piVar6;
            piVar6 = FUN_10037030(DAT_1005b790);
            if (piVar6 != (int *)0x0) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
              *piVar6 = iVar5;
              if (iVar5 == 0) {
                if (piVar6 != (int *)0x0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                  FUN_10037010(DAT_1005b790,piVar6);
                }
                piVar6 = (int *)0x0;
              }
              else {
                piVar6[2] = 0;
                piVar6[1] = 10;
              }
            }
            DAT_1005b798[2] = (int)piVar6;
            piVar6 = FUN_10037030(DAT_1005b790);
            if (piVar6 != (int *)0x0) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
              *piVar6 = iVar5;
              if (iVar5 == 0) {
                if (piVar6 != (int *)0x0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                  FUN_10037010(DAT_1005b790,piVar6);
                }
                piVar6 = (int *)0x0;
              }
              else {
                piVar6[2] = 0;
                piVar6[1] = 10;
              }
            }
            DAT_1005b798[3] = (int)piVar6;
            piVar6 = FUN_10037030(DAT_1005b790);
            if (piVar6 != (int *)0x0) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
              *piVar6 = iVar5;
              if (iVar5 == 0) {
                if (piVar6 != (int *)0x0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                  FUN_10037010(DAT_1005b790,piVar6);
                }
                piVar6 = (int *)0x0;
              }
              else {
                piVar6[2] = 0;
                piVar6[1] = 10;
              }
            }
            DAT_1005b798[4] = (int)piVar6;
            DAT_1005b798[5] = 0;
            if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
               ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))) {
              iVar5 = RwForAllClumpsInScenePointer((int)param_2,&LAB_1003e3c0,DAT_1005b798[3]);
              if (iVar5 == 0) {
                FUN_1003d550();
                return 0;
              }
              iVar5 = RwForAllLightsInScenePointer((int)param_2,FUN_1003e440,DAT_1005b798[4]);
              if (iVar5 == 0) {
                FUN_1003d550();
                return 0;
              }
              goto LAB_1003e101;
            }
            FUN_1003d550();
          }
          return 0;
        }
LAB_1003e101:
        iVar1 = RwGetChunkSize(0x52414c54,(int *)0x0,param_3);
        iVar2 = RwGetChunkSize(0x54454c54,(int *)0x0,param_3);
        iVar3 = RwGetChunkSize(0x4d414c54,(int *)0x0,param_3);
        uVar9 = 1;
        iVar5 = RwGetChunkSize(0x53545254,(int *)0x0,4);
        iVar5 = iVar1 + iVar2 + iVar3 + 8 + iVar5;
        if (*(int *)(DAT_1005b798[4] + 8) != 0) {
          do {
            if (((uint)((int *)DAT_1005b798[4])[2] < uVar9) || (uVar9 == 0)) {
              piVar6 = (int *)0x0;
            }
            else {
              piVar6 = *(int **)(*(int *)DAT_1005b798[4] + -4 + uVar9 * 4);
            }
            uVar9 = uVar9 + 1;
            iVar1 = RwGetChunkSize(0x4c495445,piVar6,param_3);
            iVar5 = iVar5 + iVar1;
          } while (uVar9 <= *(uint *)(DAT_1005b798[4] + 8));
        }
        uVar9 = 1;
        iVar1 = RwGetChunkSize(0x53545254,(int *)0x0,4);
        iVar5 = iVar5 + iVar1;
        if (*(int *)(DAT_1005b798[3] + 8) != 0) {
          do {
            if (((uint)((int *)DAT_1005b798[3])[2] < uVar9) || (uVar9 == 0)) {
              piVar6 = (int *)0x0;
            }
            else {
              piVar6 = *(int **)(*(int *)DAT_1005b798[3] + -4 + uVar9 * 4);
            }
            uVar9 = uVar9 + 1;
            iVar1 = RwGetChunkSize(0x41544f4d,piVar6,param_3);
            iVar5 = iVar5 + iVar1;
          } while (uVar9 <= *(uint *)(DAT_1005b798[3] + 8));
        }
        if (bVar10) {
          FUN_1003d550();
        }
        return iVar5;
      }
      if (param_1 < 0x53545255) {
        if (param_1 == 0x53545254) {
          return param_3 + 8;
        }
        if (param_1 != 0x53544e47) {
          return 0;
        }
        if (param_2 == (int *)0x0) {
          return 8;
        }
        uVar9 = 0xffffffff;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          iVar5 = *param_2;
          param_2 = (int *)((int)param_2 + 1);
        } while ((char)iVar5 != '\0');
        return (~uVar9 + 3 & 0xfffffffc) + 8;
      }
      if (param_1 < 0x54455856) {
        if (param_1 == 0x54455855) {
          local_8 = (int *)FUN_10018570(param_2);
          iVar1 = RwGetChunkSize(0x53544e47,local_8,param_3);
          iVar5 = RwGetChunkSize(0x53545254,param_2,0x14);
          iVar5 = iVar1 + 8 + iVar5;
          if ((param_3 & 8) == 0) {
            if (local_8 == (int *)0x0) {
              FUN_1000cba0(0x5d);
              return 0;
            }
          }
          else {
            iVar1 = RwGetChunkSize(0x52415354,(int *)param_2[6],param_3);
            iVar5 = iVar5 + iVar1;
          }
          if (((param_3 & 8) != 0) && ((int *)param_2[7] != (int *)0x0)) {
            iVar1 = RwGetChunkSize(0x52415354,(int *)param_2[7],param_3);
            iVar5 = iVar5 + iVar1;
          }
          return iVar5;
        }
        if (param_1 != 0x54454c54) {
          return 0;
        }
        iVar5 = RwGetChunkSize(0x53545254,(int *)0x0,0xc);
        iVar5 = iVar5 + 8;
        piVar6 = (int *)0x1;
        local_8 = *(int **)(DAT_1005b798[1] + 8);
        if (local_8 != (int *)0x0) {
          do {
            if (((int *)((int *)DAT_1005b798[1])[2] < piVar6) || (piVar6 == (int *)0x0)) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = *(int **)(*(int *)DAT_1005b798[1] + -4 + (int)piVar6 * 4);
            }
            iVar1 = FUN_10018570(piVar7);
            uVar9 = param_3;
            if (iVar1 == 0) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = (int *)FUN_10018570(piVar7);
            }
            piVar6 = (int *)((int)piVar6 + 1);
            iVar1 = RwGetChunkSize(0x53544e47,piVar7,uVar9);
            iVar5 = iVar5 + 0x14 + iVar1;
          } while (piVar6 <= local_8);
        }
        return iVar5;
      }
      if (param_1 == 0x56334420) {
        iVar5 = RwGetChunkSize(0x53545254,param_2,0xc);
        return iVar5 + 8;
      }
      if (param_1 != 0x564c5354) {
        return 0;
      }
      iVar1 = *(int *)(param_2[0x22] + 8);
      iVar5 = RwGetChunkSize(0x53545254,(int *)0x0,0xc);
      iVar5 = iVar1 * (((int)(param_3 << 0x1d) >> 0x1f & 0xcU) + (param_3 & 2) * 4 + 0xc +
                      ((int)(param_3 << 0x1f) >> 0x1f & 0xcU)) + 8 + iVar5;
    }
    return iVar5;
  }
  if (param_1 == 0x44415441) {
    return (param_2[1] + 3U & 0xfffffffc) + 8;
  }
  if (param_1 != 0x434c554d) {
    return 0;
  }
  bVar10 = DAT_1005b798 == (int *)0x0;
  if (bVar10) {
    DAT_1005b798 = FUN_10037030(DAT_1005b794);
    if (DAT_1005b798 != (int *)0x0) {
      piVar6 = FUN_10037030(DAT_1005b790);
      if (piVar6 != (int *)0x0) {
        iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
        *piVar6 = iVar5;
        if (iVar5 == 0) {
          if (piVar6 != (int *)0x0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
            FUN_10037010(DAT_1005b790,piVar6);
          }
          piVar6 = (int *)0x0;
        }
        else {
          piVar6[2] = 0;
          piVar6[1] = 10;
        }
      }
      *DAT_1005b798 = (int)piVar6;
      piVar6 = FUN_10037030(DAT_1005b790);
      if (piVar6 != (int *)0x0) {
        iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
        *piVar6 = iVar5;
        if (iVar5 == 0) {
          if (piVar6 != (int *)0x0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
            FUN_10037010(DAT_1005b790,piVar6);
          }
          piVar6 = (int *)0x0;
        }
        else {
          piVar6[2] = 0;
          piVar6[1] = 10;
        }
      }
      DAT_1005b798[1] = (int)piVar6;
      piVar6 = FUN_10037030(DAT_1005b790);
      if (piVar6 != (int *)0x0) {
        iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
        *piVar6 = iVar5;
        if (iVar5 == 0) {
          if (piVar6 != (int *)0x0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
            FUN_10037010(DAT_1005b790,piVar6);
          }
          piVar6 = (int *)0x0;
        }
        else {
          piVar6[2] = 0;
          piVar6[1] = 10;
        }
      }
      DAT_1005b798[2] = (int)piVar6;
      piVar6 = FUN_10037030(DAT_1005b790);
      if (piVar6 != (int *)0x0) {
        iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
        *piVar6 = iVar5;
        if (iVar5 == 0) {
          if (piVar6 != (int *)0x0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
            FUN_10037010(DAT_1005b790,piVar6);
          }
          piVar6 = (int *)0x0;
        }
        else {
          piVar6[2] = 0;
          piVar6[1] = 10;
        }
      }
      DAT_1005b798[3] = (int)piVar6;
      piVar6 = FUN_10037030(DAT_1005b790);
      if (piVar6 != (int *)0x0) {
        iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
        *piVar6 = iVar5;
        if (iVar5 == 0) {
          if (piVar6 != (int *)0x0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
            FUN_10037010(DAT_1005b790,piVar6);
          }
          piVar6 = (int *)0x0;
        }
        else {
          piVar6[2] = 0;
          piVar6[1] = 10;
        }
      }
      DAT_1005b798[4] = (int)piVar6;
      DAT_1005b798[5] = 0;
      if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
         ((piVar6 = (int *)DAT_1005b798[3], piVar6 != (int *)0x0 && (DAT_1005b798[4] != 0)))) {
        piVar7 = (int *)(*piVar6 + piVar6[2] * 4);
        iVar5 = piVar6[2];
        do {
          piVar7 = piVar7 + -1;
          if (iVar5 == 0) {
            uVar9 = piVar6[1];
            if ((uint)piVar6[2] < uVar9) {
LAB_1003dba1:
              *(int **)(*piVar6 + piVar6[2] * 4) = param_2;
              piVar6[2] = piVar6[2] + 1;
            }
            else {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar6,uVar9 * 4 + 0xa0);
              if (iVar5 != 0) {
                *piVar6 = iVar5;
                piVar6[1] = uVar9 + 0x28;
                goto LAB_1003dba1;
              }
            }
            FUN_1003e4c0();
            goto LAB_1003dbcc;
          }
          iVar5 = iVar5 + -1;
        } while ((int *)*piVar7 != param_2);
        FUN_1003e4c0();
        goto LAB_1003dbcc;
      }
      FUN_1003d550();
    }
    return 0;
  }
LAB_1003dbcc:
  iVar5 = RwGetChunkSize(0x52414c54,(int *)0x0,param_3);
  iVar1 = RwGetChunkSize(0x54454c54,(int *)0x0,param_3);
  iVar2 = RwGetChunkSize(0x4d414c54,(int *)0x0,param_3);
  iVar3 = RwGetChunkSize(0x41544f4d,param_2,param_3);
  if (bVar10) {
    FUN_1003d550();
  }
  return iVar5 + iVar1 + iVar2 + 8 + iVar3;
}


