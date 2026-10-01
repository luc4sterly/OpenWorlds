// 004036a6 FUN_004036a6 [Global]
// program: run.exe

int * __thiscall FUN_004036a6(void *this,int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  byte *pbVar5;
  uint *puVar6;
  void *local_8;
  
  local_8 = this;
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_0040253a((undefined *)param_1);
    }
    else {
      puVar6 = param_2;
      if (DAT_0040ce64 == 3) {
        do {
          if (puVar6 < (uint *)0xffffffe1) {
            puVar2 = (uint *)FUN_00403c11((int)param_1);
            if (puVar2 == (uint *)0x0) {
LAB_0040379d:
              if (puVar6 == (uint *)0x0) {
                puVar6 = (uint *)0x1;
              }
              puVar6 = (uint *)((int)puVar6 + 0xfU & 0xfffffff0);
              piVar1 = HeapReAlloc(DAT_0040ce60,0,param_1,(SIZE_T)puVar6);
            }
            else {
              if (DAT_0040ce5c < puVar6) {
LAB_00403756:
                if (puVar6 == (uint *)0x0) {
                  puVar6 = (uint *)0x1;
                }
                puVar6 = (uint *)((int)puVar6 + 0xfU & 0xfffffff0);
                piVar1 = HeapAlloc(DAT_0040ce60,0,(SIZE_T)puVar6);
                if (piVar1 != (int *)0x0) {
                  puVar4 = (uint *)(param_1[-1] - 1U);
                  if (puVar6 <= (uint *)(param_1[-1] - 1U)) {
                    puVar4 = puVar6;
                  }
                  FUN_00405c00(piVar1,param_1,(uint)puVar4);
                  FUN_00403c3c(puVar2,(int)param_1);
                }
              }
              else {
                iVar3 = FUN_0040441a(puVar2,(int)param_1,(int)puVar6);
                piVar1 = param_1;
                if (iVar3 == 0) {
                  piVar1 = FUN_00403f65(puVar6);
                  if (piVar1 == (int *)0x0) goto LAB_00403756;
                  puVar2 = (uint *)(param_1[-1] - 1U);
                  if (puVar6 <= (uint *)(param_1[-1] - 1U)) {
                    puVar2 = puVar6;
                  }
                  FUN_00405c00(piVar1,param_1,(uint)puVar2);
                  puVar2 = (uint *)FUN_00403c11((int)param_1);
                  FUN_00403c3c(puVar2,(int)param_1);
                }
                if (piVar1 == (int *)0x0) goto LAB_00403756;
              }
              if (puVar2 == (uint *)0x0) goto LAB_0040379d;
            }
            if (piVar1 != (int *)0x0) {
              return piVar1;
            }
          }
          if (DAT_0040bb94 == 0) {
            return (int *)0x0;
          }
          iVar3 = FUN_00403bae(puVar6);
        } while (iVar3 != 0);
      }
      else if (DAT_0040ce64 == 2) {
        if (param_2 < (uint *)0xffffffe1) {
          if (param_2 == (uint *)0x0) {
            puVar6 = (uint *)0x10;
          }
          else {
            puVar6 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
          }
        }
        do {
          if (puVar6 < (uint *)0xffffffe1) {
            pbVar5 = (byte *)FUN_0040496c((undefined *)param_1,&local_8,(uint *)&param_2);
            if (pbVar5 == (byte *)0x0) {
              piVar1 = HeapReAlloc(DAT_0040ce60,0,param_1,(SIZE_T)puVar6);
            }
            else {
              if (puVar6 < DAT_0040b314) {
                iVar3 = FUN_00404d34((int)local_8,(int *)param_2,pbVar5,(uint)puVar6 >> 4);
                piVar1 = param_1;
                if (iVar3 == 0) {
                  piVar1 = FUN_00404a08((uint)puVar6 >> 4);
                  if (piVar1 == (int *)0x0) goto LAB_0040388b;
                  puVar2 = (uint *)((uint)*pbVar5 << 4);
                  if (puVar6 <= (uint *)((uint)*pbVar5 << 4)) {
                    puVar2 = puVar6;
                  }
                  FUN_00405c00(piVar1,param_1,(uint)puVar2);
                  FUN_004049c3((int)local_8,(int)param_2,pbVar5);
                }
                if (piVar1 != (int *)0x0) {
                  return piVar1;
                }
              }
LAB_0040388b:
              piVar1 = HeapAlloc(DAT_0040ce60,0,(SIZE_T)puVar6);
              if (piVar1 == (int *)0x0) goto LAB_004038e3;
              puVar2 = (uint *)((uint)*pbVar5 << 4);
              if (puVar6 <= (uint *)((uint)*pbVar5 << 4)) {
                puVar2 = puVar6;
              }
              FUN_00405c00(piVar1,param_1,(uint)puVar2);
              FUN_004049c3((int)local_8,(int)param_2,pbVar5);
            }
            if (piVar1 != (int *)0x0) {
              return piVar1;
            }
          }
LAB_004038e3:
          if (DAT_0040bb94 == 0) {
            return (int *)0x0;
          }
          iVar3 = FUN_00403bae(puVar6);
        } while (iVar3 != 0);
      }
      else {
        do {
          if (puVar6 < (uint *)0xffffffe1) {
            if (puVar6 == (uint *)0x0) {
              puVar6 = (uint *)0x1;
            }
            puVar6 = (uint *)((int)puVar6 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_0040ce60,0,param_1,(SIZE_T)puVar6);
            if (piVar1 != (int *)0x0) {
              return piVar1;
            }
          }
          if (DAT_0040bb94 == 0) {
            return (int *)0x0;
          }
          iVar3 = FUN_00403bae(puVar6);
        } while (iVar3 != 0);
      }
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}


