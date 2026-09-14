// 00406bd0 FUN_00406bd0 [Global]
// programa: gamma.dll

undefined4 *
FUN_00406bd0(undefined4 *param_1,int *param_2,void *param_3,byte param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  byte local_31;
  byte local_30 [40];
  
  iVar1 = FUN_00406d10(param_3,CONCAT44(param_6,param_5),local_30);
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&local_31,0,local_30,iVar1);
  return param_1;
}


