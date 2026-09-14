// 0041ab60 Java_NET_worlds_scape_Point3Temp_times__LNET_worlds_scape_Transform_2 [Global]
// programa: gamma.dll

/* class _jobject * __stdcall
   Java_NET_worlds_scape_Point3Temp_times__LNET_worlds_scape_Transform_2(struct JNIEnv_ *,class
   _jobject *,class _jobject *) */

_jobject *
Java_NET_worlds_scape_Point3Temp_times__LNET_worlds_scape_Transform_2
          (JNIEnv_ *param_1,_jobject *param_2,_jobject *param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* 0x1ab60  5
                       ?Java_NET_worlds_scape_Point3Temp_times__LNET_worlds_scape_Transform_2@@YGPAV_jobject@@PAUJNIEnv_@@PAV1@1@Z
                        */
  fVar2 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_004895d4);
  local_1c = (float)fVar2;
  fVar2 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_004895d8);
  local_18 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_004895dc);
  local_14 = (float)fVar2;
  uVar1 = FUN_00425380((int *)param_1,param_3);
  FUN_0041a080(&local_1c,uVar1);
  (**(code **)(*(int *)param_1 + 0x1bc))(param_1,param_2,DAT_004895d4,local_1c);
  (**(code **)(*(int *)param_1 + 0x1bc))(param_1,param_2,DAT_004895d8,local_18);
  (**(code **)(*(int *)param_1 + 0x1bc))(param_1,param_2,DAT_004895dc,local_14);
  return param_2;
}


