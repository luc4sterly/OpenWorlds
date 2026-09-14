// 00457730 FUN_00457730 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00457730(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  if ((param_1 != (uint *)0x0) && (param_2 != (int *)0x0)) {
    param_1[3] = param_1[3] - 1;
    iVar1 = FUN_004575c0(param_1,0x3c,(int *)(param_1 + 1));
    if (iVar1 != 0) {
      iVar1 = FUN_004575c0(param_1 + 1,0x3c,(int *)(param_1 + 2));
      if (iVar1 != 0) {
        iVar1 = FUN_004575c0(param_1 + 2,0x18,(int *)(param_1 + 3));
        if (iVar1 != 0) {
          iVar1 = FUN_004575c0(param_1 + 4,0xc,(int *)(param_1 + 5));
          if (iVar1 != 0) {
            local_10 = param_1[5];
            iVar1 = FUN_00458ee0((int *)&local_10,0x16d);
            if (iVar1 != 0) {
              iVar1 = FUN_00457520(param_1[5],param_1[4]);
              iVar1 = FUN_00458e90((int *)&local_10,iVar1);
              if (iVar1 != 0) {
                iVar1 = FUN_00458e90((int *)&local_10,
                                     (int)*(short *)(&DAT_00482a18 + param_1[4] * 2));
                if (iVar1 != 0) {
                  iVar1 = FUN_00458e90((int *)&local_10,param_1[3]);
                  if (((iVar1 != 0) && (-1 < (int)local_10)) && (local_10 < 0xc22f)) {
                    uVar2 = param_1[1] * 0x3c + param_1[2] * 0xe10 + *param_1;
                    if (uVar2 <= local_10 * -0x15180 - 1) {
                      iVar1 = uVar2 + local_10 * 0x15180;
                      *param_2 = iVar1 + 0x7c558180;
                      FUN_00457600(iVar1 + 0x7c558180,param_1);
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return 0;
  }
  return 0;
}


