#include <ft_get_features.h>

TEST_F(ft_get_features, Given_NULLGroup_And_Correct_Config_And_Output_When_Train_Without_Incremental_Then_EDCC_NULL_POINTER_ERROR)
{
    int ret = EDCC::GetTrainingSetFeatures(NULL,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_NULL_POINTER_ERROR);
}

TEST_F(ft_get_features, Given_Correct_Group_And_NULLConfig_And_Correct_Output_When_Train_Without_Incremental_Then_EDCC_NULL_POINTER_ERROR)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           NULL,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_NULL_POINTER_ERROR);
}

TEST_F(ft_get_features, Given_Correct_Group_And_Config_And_NULLOutput_When_Train_Without_Incremental_Then_EDCC_NULL_POINTER_ERROR)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           NULL);
    EXPECT_EQ(ret, EDCC_NULL_POINTER_ERROR);
}

TEST_F(ft_get_features, Given_Correct_Group_And_Config_And_Output_When_Train_Without_Incremental_Then_EDCC_SUCCESS)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_SUCCESS);
    CheckFeaturesConfigEqualConfigFile(FEATURES_OUTPUT_PATH, CORRECT_CONFIG_PATH);
    CheckOneIdentityImageCountInFeatures(FEATURES_OUTPUT_PATH, "1", 6);
    CheckOneIdentityImageCountInFeatures(FEATURES_OUTPUT_PATH, "2", 6);
}

TEST_F(ft_get_features, Given_Correct_Group_And_ConfigNotExists_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_CONFIG_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           NOT_EXISTS_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_LOAD_CONFIG_FAIL);
}

TEST_F(ft_get_features, Given_Correct_Group_And_ConfigParamsError_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_CONFIG_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           PARAMS_ERROR_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_LOAD_CONFIG_FAIL);
}

TEST_F(ft_get_features, Given_Correct_Group_And_ConfigParamsMiss_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_CONFIG_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           PARAMS_MISS_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_LOAD_CONFIG_FAIL);
}

TEST_F(ft_get_features, Given_Correct_Group_And_ConfigParamsNoDefault_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_CONFIG_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           PARAMS_NO_DEFAULT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_LOAD_CONFIG_FAIL);
}

TEST_F(ft_get_features, Given_Correct_Group_And_ConfigParamsOver_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_CONFIG_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           PARAMS_OVER_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_LOAD_CONFIG_FAIL);
}

TEST_F(ft_get_features, Given_GroupWrongFormat_And_Correct_Config_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_TAINING_SET_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(WRONG_FORMAT_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_LOAD_TAINING_SET_FAIL);
}

TEST_F(ft_get_features, Given_GroupNotExists_And_Correct_Config_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_TAINING_SET_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(WRONG_FORMAT_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);

    EXPECT_EQ(ret, EDCC_LOAD_TAINING_SET_FAIL);
}

TEST_F(ft_get_features, Given_GroupConflictImage_And_Correct_Config_And_Output_When_Train_Without_Incremental_Then_EDCC_LOAD_TAINING_SET_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CONFLICT_IMAGE_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);

    EXPECT_EQ(ret, EDCC_LOAD_TAINING_SET_FAIL);
}

TEST_F(ft_get_features, Given_GroupSomeImageError_And_Correct_Config_And_Output_When_Train_Without_Incremental_Then_EDCC_SUCCESS_And_Count_Correct)
{
    int ret = EDCC::GetTrainingSetFeatures(SOME_IMAGE_ERROR_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);

    EXPECT_EQ(ret, EDCC_SUCCESS);
    CheckOneIdentityImageCountInFeatures(FEATURES_OUTPUT_PATH, "1", 5);
    CheckOneIdentityImageCountInFeatures(FEATURES_OUTPUT_PATH, "2", 4);
}

TEST_F(ft_get_features, Given_Correct_Group_And_Config_And_Output_When_Features_Has_Data_And_Train_Without_Incremental_Then_EDCC_SUCCESS_And_Data_Cover)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_SUCCESS);

    ret = EDCC::GetTrainingSetFeatures(INCREMENTAL_GROUP_PATH,
                                       INCREMENTAL_CONFIG_PATH,
                                       FEATURES_OUTPUT_PATH);
    EXPECT_EQ(ret, EDCC_SUCCESS);
    CheckFeaturesConfigEqualConfigFile(FEATURES_OUTPUT_PATH, INCREMENTAL_CONFIG_PATH);
    CheckOneIdentityImageCountInFeatures(FEATURES_OUTPUT_PATH, "3", 6);
    CheckOneIdentityImageCountInFeatures(FEATURES_OUTPUT_PATH, "4", 6);
}

TEST_F(ft_get_features, Given_Correct_Group_And_Config_And_OutputCantCreate_When_Train_Without_Incremental_Then_EDCC_SAVE_FEATURES_FAIL)
{
    int ret = EDCC::GetTrainingSetFeatures(CORRECT_GROUP_PATH,
                                           CORRECT_CONFIG_PATH,
                                           FEATURES_OUTPUT_PATH_CANT_CREATE);
    EXPECT_EQ(ret, EDCC_SAVE_FEATURES_FAIL);
}
