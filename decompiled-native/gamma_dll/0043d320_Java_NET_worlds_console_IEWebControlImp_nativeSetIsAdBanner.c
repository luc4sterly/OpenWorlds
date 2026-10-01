// 0043d320 Java_NET_worlds_console_IEWebControlImp_nativeSetIsAdBanner [Global]
// program: gamma.dll

/* void __stdcall Java_NET_worlds_console_IEWebControlImp_nativeSetIsAdBanner(struct JNIEnv_ *,class
   _jobject *,unsigned char) */

void Java_NET_worlds_console_IEWebControlImp_nativeSetIsAdBanner
               (JNIEnv_ *param_1,_jobject *param_2,uchar param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
                    /* 0x3d320  1
                       ?Java_NET_worlds_console_IEWebControlImp_nativeSetIsAdBanner@@YGXPAUJNIEnv_@@PAV_jobject@@E@Z
                        */
  uVar1 = (**(code **)(*(int *)param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*(int *)param_1 + 0x178))
                    (param_1,uVar1,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar2 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar3 = (uint *)(**(code **)(*(int *)param_1 + 400))(param_1,param_2,iVar2);
  if (puVar3 == (uint *)0x0) {
    puVar3 = FUN_0044e010(0x3c);
    puVar5 = puVar3;
    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    (**(code **)(*(int *)param_1 + 0x1b4))(param_1,param_2,iVar2,puVar3);
  }
  if ((void *)puVar3[2] == (void *)0x0) {
    return;
  }
  FUN_0043e990((void *)puVar3[2],(uint)param_3);
  return;
}


