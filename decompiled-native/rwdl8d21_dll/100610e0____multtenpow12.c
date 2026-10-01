// 100610e0 ___multtenpow12 [Global]
// program: RWDL8D21.DLL

/* Library Function - Single Match
    ___multtenpow12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___multtenpow12(int *param_1,uint param_2,int param_3)

{
  undefined **ppuVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  uint uVar5;
  undefined2 local_c;
  undefined4 uStack_a;
  undefined2 uStack_6;
  undefined *local_4;
  
  ppuVar4 = &PTR_s_M_d_yy_100776c0;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      ppuVar4 = (undefined **)&DAT_10077820;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      ppuVar4 = ppuVar4 + 0x15;
      uVar5 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar5;
      if (uVar2 != 0) {
        ppuVar1 = ppuVar4 + uVar2 * 3;
        ppuVar3 = ppuVar1;
        if (0x7fff < *(ushort *)ppuVar1) {
          ppuVar3 = (undefined **)&local_c;
          local_c = SUB42(*ppuVar1,0);
          uStack_a._0_2_ = (undefined2)((uint)*ppuVar1 >> 0x10);
          uStack_a._2_2_ = SUB42(ppuVar1[1],0);
          uStack_6 = (undefined2)((uint)ppuVar1[1] >> 0x10);
          local_4 = ppuVar1[2];
          uStack_a = CONCAT22(uStack_a._2_2_,(undefined2)uStack_a) + -1;
        }
        ___ld12mul(param_1,(int *)ppuVar3);
      }
    }
  }
  return;
}


