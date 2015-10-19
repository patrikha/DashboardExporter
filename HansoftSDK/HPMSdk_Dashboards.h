
/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	File:			Hansoft Project Manager SDK Dashboards										|
|																								|
|	Author:			Erik Olofsson																|
|																								|
|	Copyright:		Hansoft AB, 2009															|
|																								|
|	Contents:		Hansoft Project Manager SDK													|
|																								|
|	Location:		/Hansoft PM SDK/Reference/12 - Dashboards									|
|																								|
|	Section:		Reference																	|
|																								|
|	History:																					|
|																								|
\*_____________________________________________________________________________________________*/

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Layout type used for @{HPMDashboardPageLayout}::m_Type.						|
|																									|
|	See Also:			@{HPMDashboardPageLayout}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardPageLayoutType
{
	EHPMDashboardPageLayoutType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardPageLayoutType_SingleColumn,				// Single column layout.
	EHPMDashboardPageLayoutType_TwoColumns,					// Two column layout.
	EHPMDashboardPageLayoutType_ThreeColumns,				// Three column layout.
	EHPMDashboardPageLayoutType_FourColumns,				// Four column layout.
	EHPMDashboardPageLayoutType_Highway,					// Four column layout (20%,30%,30%,20%).
	EHPMDashboardPageLayoutType_CenterLane,					// Three column layout (30%,40%,30%).
	EHPMDashboardPageLayoutType_Sidewalk,					// Two column layout (40%,60%).
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Data type used for @{HPMDashboardChartResultSetElementInfo}::m_Type.		|
|																									|
|	See Also:			@{HPMDashboardChartResultSetElementInfo}									|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartResultDataType
{
	EHPMDashboardChartResultDataType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartResultDataType_HPMString,					// The result data is of the type string.
	EHPMDashboardChartResultDataType_HPMFP64,					// The result data is of the type float.
	EHPMDashboardChartResultDataType_HPMUInt64,					// The result data is of the type integer.
	EHPMDashboardChartResultDataType_Binary,					// The result data is of the type binary.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Sub data type used for @{HPMDashboardChartResultSetElementInfo}::m_SubType.	|
|																									|
|	See Also:			@{HPMDashboardChartResultSetElementInfo}									|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartResultDataSubType
{
	EHPMDashboardChartResultDataSubType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartResultDataSubType_None,						// No sub type.
	EHPMDashboardChartResultDataSubType_Normal,						// Interpret the value as a plain value of the data type.
	EHPMDashboardChartResultDataSubType_Time,						// Interpret the value as a time value.
	EHPMDashboardChartResultDataSubType_RowIndex,					// Interpret the value as a row index.
	EHPMDashboardChartResultDataSubType_UntranslatedString,			// Interpret the value as a untranslated string.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart types used for  @{HPMDashboardChartPresentationConfig}::m_Type.		|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartType
{
	EHPMDashboardChartType_NewVersionOfSDKRequired,		// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartType_Bar,							// Bar chart type.
	EHPMDashboardChartType_Pie,							// Pie chart type.
	EHPMDashboardChartType_Line,						// Line chart type.
	EHPMDashboardChartType_Area,						// Area chart type.
	EHPMDashboardChartType_XY,							// XY chart type.
	EHPMDashboardChartType_Gauge,						// Gauge chart type.
	EHPMDashboardChartType_Table,						// Table chart type.
	EHPMDashboardChartType_ItemView,					// Item view chart type.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart orientation used for													|
|						@{HPMDashboardChartResultSetElementInfo}::m_Orientation.					|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartOrientation
{
	EHPMDashboardChartOrientation_NewVersionOfSDKRequired,		// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartOrientation_Vertical,						// Vertical orientation.
	EHPMDashboardChartOrientation_Horizontal,					// Horizontal orientation.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Legend settings used for @{HPMDashboardChartResultSetElementInfo}::m_Legend.|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartLegend
{
	EHPMDashboardChartLegend_NewVersionOfSDKRequired,		// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartLegend_NotVisible,					// Legend not visible.
	EHPMDashboardChartLegend_Visible,						// Legend visible.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Label settings used for @{HPMDashboardChartPresentationConfig}::m_Label.	|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartLabel
{
	EHPMDashboardChartLabel_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartLabel_NotVisible,					// Label not visible.
	EHPMDashboardChartLabel_Name,						// Label displays name.
	EHPMDashboardChartLabel_Value,						// Label displays value.
	EHPMDashboardChartLabel_Percentage,					// Label displays percentage.
	EHPMDashboardChartLabel_NameAndValue,				// Label displays name and value.
	EHPMDashboardChartLabel_NameAndPercentage,			// Label displays name and percentage.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Grouping settings used for													|
|						@{HPMDashboardChartPresentationConfig}::m_Grouping.							|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartGrouping
{
	EHPMDashboardChartGrouping_NewVersionOfSDKRequired,		// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartGrouping_None,						// No grouping.
	EHPMDashboardChartGrouping_Stack,						// Stacked grouping.
	EHPMDashboardChartGrouping_StackPercentage,				// Stacked percentage grouping.
};



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Enabled settings in @{HPMDashboardChartPresentationConfig},					|
|						used for @{HPMDashboardChartPresentationConfig}::m_Enabled					|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartPresentationSettingEnabled
{
	EHPMDashboardChartPresentationSettingEnabled_None = 0,					// No settings
	EHPMDashboardChartPresentationSettingEnabled_Type = 1 << 0,				// Type setting is enabled
	EHPMDashboardChartPresentationSettingEnabled_Legend = 1 << 1,			// Legend setting is enabled
	EHPMDashboardChartPresentationSettingEnabled_Labels = 1 << 2,			// Labels setting is enabled
	EHPMDashboardChartPresentationSettingEnabled_Grouping = 1 << 3,			// Grouping setting is enabled
	EHPMDashboardChartPresentationSettingEnabled_Orientation = 1 << 4,		// Orientation setting is enabled
	EHPMDashboardChartPresentationSettingEnabled_Bounds = 1 << 5,			// Bounds setting is enabled
	EHPMDashboardChartPresentationSettingEnabled_IdealBurndown = 1 << 6,	// Ideal burndown setting is enabled
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Flags for @{HPMDashboardChartIdealBurndown},								|
|						used for @{HPMDashboardChartIdealBurndown}::m_Flags							|
|																									|
|	See Also:			@{HPMDashboardChartIdealBurndown}											|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartPresentationIdealBurndownFlags
{
	EHPMDashboardChartPresentationIdealBurndownFlags_None = 0,					// No settings
	EHPMDashboardChartPresentationIdealBurndownFlags_Enabled = 1 << 0,			// Ideal burndown is enabled
	EHPMDashboardChartPresentationIdealBurndownFlags_OverrideValue = 1 << 1,	// Starting value override is enabled
	EHPMDashboardChartPresentationIdealBurndownFlags_OverrideUnit = 1 << 2,		// Starting unit override is enabled
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Used to store information about a chart in a page layout.					|
|																									|
|	See Also:			@{DashboardPageGetLayout}, @{DashboardPageSetLayout}						|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
|																									|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardPageLayoutChart
{
	HPMUniqueID m_ChartID;	// The unique id of the chart that this layout entry is for.
} HPMDashboardPageLayoutChart;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Used to store information about a column in a page layout					|
|																									|
|	See Also:			@{DashboardPageGetLayout}, @{DashboardPageSetLayout}						|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
|																									|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardPageLayoutColumn
{
	HPMUInt32 m_nCharts;							// Number of charts in the column.
	HPMDashboardPageLayoutChart const* m_pCharts;	// Pointer to a list of charts in the column. See @{HPMDashboardPageLayoutChart}.
} HPMDashboardPageLayoutColumn;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Used to store information about a page layout								|
|																									|
|	See Also:			@{DashboardPageGetLayout}, @{DashboardPageSetLayout}						|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
|																									|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardPageLayout
{
	HPMUInt32 m_Type;								// [type=EHPMDashboardPageLayoutType,default=EHPMDashboardPageLayoutType_Sidewalk]. The type of the layout. Can be one of @{EHPMDashboardPageLayoutType}.
	HPMUInt32 m_nColumns;							// The number of columns in the layout.
	HPMDashboardPageLayoutColumn const* m_pColumns;	// Pointer to a list of columns in the layout. See @{HPMDashboardPageLayoutColumn}.
} HPMDashboardPageLayout;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Data info for a chart.														|
|																									|
|	See Also:			@{HPMDashboardChartResultSet}												|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSetInfo
{
	HPMUInt32 m_ForecastingStart;	// Forecasting start index
} HPMDashboardChartResultSetInfo;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Boundary values for a chart. Currently used if								|
|						@{HPMDashboardChartPresentationConfig}::m_Type is							|
|						@{EHPMDashboardChartType}_Gauge.											|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartBounds
{
	HPMFP64 m_Lower; // [default=0] The lower bound of the chart.
	HPMFP64 m_Upper; // [default=0] The upper bound of the chart.
} HPMDashboardChartBounds;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Ideal burndown settings. Only used if										|
|						@{HPMDashboardChartPresentationConfig}::m_Type is							|
|						@{EHPMDashboardChartType}_Line or											|
|						@{EHPMDashboardChartType}_Area.												|
|																									|
|	See Also:			@{HPMDashboardChartPresentationConfig}										|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartIdealBurndown
{
	HPMUInt32 m_Flags;		// [type=EHPMDashboardChartPresentationIdealBurndownFlags,default=EHPMDashboardChartPresentationIdealBurndownFlags_None]. Bit field controlling the ideal burndown line. Can be any combination of @{EHPMDashboardChartPresentationIdealBurndownFlags}.
	HPMFP64 m_StartValue;	// [default=0] The starting value of the ideal burndown line. Only used if start value override flag is set.
	HPMUInt32 m_StartUnit;	// [default=1] The starting unit (day, week etc) of the ideal burndown line. Only used if start unit override flag is set.
} HPMDashboardChartIdealBurndown;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Presentation config for a chart.											|
|																									|
|	See Also:			@{HPMDashboardChartResultSet}												|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartPresentationConfig
{
	HPMUInt32 m_Enabled;				// [type=EHPMDashboardChartPresentationSettingEnabled,default=EHPMDashboardChartPresentationSettingEnabled_None]. Bit field showing what presentation configuration values are set. Can be any combination of @{EHPMDashboardChartPresentationSettingEnabled}.
	
	HPMUInt32 m_Type;					// [type=EHPMDashboardChartType,default=EHPMDashboardChartType_Bar]. The type of the chart. Can be one of @{EHPMDashboardChartType}.
	HPMUInt32 m_Legend;					// [type=EHPMDashboardChartLegend,default=EHPMDashboardChartLegend_Visible]. The legend settings of the chart. Can be one of @{EHPMDashboardChartLegend}.
	HPMUInt32 m_Labels;					// [type=EHPMDashboardChartLabel,default=EHPMDashboardChartLabel_NotVisible]. The label settings of the chart. Can be one of @{EHPMDashboardChartLabel}.
	HPMUInt32 m_Grouping;				// [type=EHPMDashboardChartGrouping,default=EHPMDashboardChartGrouping_None]. The grouping settings of the chart. Can be one of @{EHPMDashboardChartGrouping}.
	HPMUInt32 m_Orientation;			// [type=EHPMDashboardChartOrientation,default=EHPMDashboardChartOrientation_Vertical]. The orientation sttings of the chart. Can be one of @{EHPMDashboardChartOrientation}.
	HPMDashboardChartBounds m_Bounds;	// The bounds of the chart. See @{HPMDashboardChartBounds}.
	HPMDashboardChartIdealBurndown m_IdealBurndown;	// The ideal burndown. See @{HPMDashboardChartIdealBurndown}.
	
	HPMChar const* m_pTheme;			// The current theme of the chart. 
} HPMDashboardChartPresentationConfig;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Used to keep a reference to a chart subscription.							|
|																									|
|	See Also:			@{DashboardSubscribeToChart}												|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
|																									|
|	Managed:			SaveOriginalRet																|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartSubscription
{
	HPMUniqueID m_ChartID;	// The unique id of the chart that this subscription is for.
	HPMInt32 m_Dummy;		// Unused dummy member
} HPMDashboardChartSubscription;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Row data value for a dimension or a measure.								|
|																									|
|						If @{HPMDashboardChartResultSetElementInfo}::m_Type is						|
|																									|
|		EHPMDashboardChartResultDataType_HPMString:	Use @{VariantDecode_HPMString}.					|
|		EHPMDashboardChartResultDataType_HPMFP64:	Use @{VariantDecode_HPMFP64}.					|
|		EHPMDashboardChartResultDataType_HPMUInt64:	Use @{VariantDecode_HPMUInt64}.					|
|		EHPMDashboardChartResultDataType_Binary:	Use @{VariantDecode_HPMBinaryBuffer}.			|
|																									|
|						If 	@{HPMDashboardChartResultSetElementInfo}::m_SubType is					|
|						EHPMDashboardChartResultDataSubType_UntranslatedString and					|
|						@{HPMDashboardChartResultSetElementInfo}::m_Type is							|
|																									|
|		EHPMDashboardChartResultDataType_Binary:	Use @{VariantDecode_HPMUntranslatedString}.		|
|																									|
|	See Also:			@{HPMVariantData}															|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSetValue
{
	HPMUInt32 m_Index;						// The index of the dimension or measure row data.
	HPMVariantData const* m_pVariantData;	// A variant to specify the data. Use the VariantDecode_* and VariantEncode_* functions to manipulate this member. Valid types are HPMUInt64, HPMFP64, HPMString, HPMUntranslatedString and HPMBinaryBuffer
} HPMDashboardChartResultSetValue;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart row data for a dimension or measure.									|
|																									|
|	See Also:			@{HPMDashboardChartResultSetValue}											|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSetRow
{
	HPMUInt32 m_nValues;								// The number of values.
	HPMDashboardChartResultSetValue const* m_pValues;	// Pointer to a list of @{HPMDashboardChartResultSetValue} that specifies the data values for the row.
} HPMDashboardChartResultSetRow;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Data info for a dimension or measure.										|				
|																									|
|	See Also:			@{HPMDashboardChartResultSetDimensions}										|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSetElementInfo
{
	HPMUInt32 m_Type;						// [type=EHPMDashboardChartResultDataType,default=EHPMDashboardChartResultDataType_NewVersionOfSDKRequired]. The type of the dimension. Can be one of @{EHPMDashboardChartResultDataType}. 
	HPMUInt32 m_SubType;					// [type=EHPMDashboardChartResultDataSubType,default=EHPMDashboardChartResultDataSubType_NewVersionOfSDKRequired]. The sub type of the dimension. Can be one of @{EHPMDashboardChartResultDataSubType}. 
	HPMUInt32 m_Index;						// The index of the dimension or measure.
	HPMFP64 m_ValueLimitLower;				// Lowe value limit. The value will be infinity to indicate that no limit is set.
	HPMFP64 m_ValueLimitUpper;				// Upper value limit. The value will be infinity to indicate that no limit is set.
	HPMUntranslatedString const* m_pName;	// The name of the dimension or measure.
} HPMDashboardChartResultSetElementInfo;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Dimension data for a dashboard chart.										|
|																									|
|	See Also:			@{HPMDashboardChartResultSetElementInfo}, @{HPMDashboardChartResultSetRow}	|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSetMeasures
{
	HPMUInt32 m_nMeasureInfos;										// The number of @{HPMDashboardChartResultSetElementInfo}.
	HPMDashboardChartResultSetElementInfo const* m_pMeasureInfos;	// Pointer to a list of @{HPMDashboardChartResultSetElementInfo} that specifies the data info for the measures.
	HPMUInt32 m_nRows;												// The number of rows.
	HPMDashboardChartResultSetRow const* m_pRows;					// Pointer to a @{HPMDashboardChartResultSetRow} of strings contains the measure row data.
} HPMDashboardChartResultSetMeasures;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Dimension data for a dashboard chart.										|
|																									|
|	See Also:			@{HPMDashboardChartResultSetElementInfo}, @{HPMDashboardChartResultSetRow}	|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSetDimensions
{
	HPMUInt32 m_nDimensionInfos;									// The number of @{HPMDashboardChartResultSetElementInfo}.
	HPMDashboardChartResultSetElementInfo const* m_pDimensionInfos;	// Pointer to a list of @{HPMDashboardChartResultSetElementInfo} that specifies the data info for the dimensions.
	HPMUInt32 m_nRows;												// The number of rows.
	HPMDashboardChartResultSetRow const* m_pRows;					// Pointer to a @{HPMDashboardChartResultSetRow} of strings contains the dimension row data.
} HPMDashboardChartResultSetDimensions;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Dashboard chart result set.													|
|																									|
|	See Also:			@{HPMDashboardChartResultSetDimensions}, 									|
|						@{HPMDashboardChartResultSetMeasures}										|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartResultSet
{
	HPMDashboardChartResultSetInfo m_Info;				// Chart info for the chart.
	HPMDashboardChartPresentationConfig m_Config;		// Presentation config for the chart.
	HPMDashboardChartResultSetDimensions m_Dimensions;	// The dimensions for the chart.
	HPMDashboardChartResultSetMeasures m_Measures;		// The measures for the chart.
} HPMDashboardChartResultSet;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Data identifier that stores different id's depending on the usage. See		|
|						the documentation where it is used.											|
|																									|
|	See Also:			@{HPMDashboardChartLimitByDataIdentifiers}, 								|
|						@{HPMDashboardChartFilter}, @{HPMDashboardChartMeasure},					|
|						@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartDataIdentifier
{
	HPMInt32 m_ID;				// [default=-1] Id 1. Can be @{EHPMDashboardChartFilterProjectType}, report id,  @{EHPMProjectDefaultColumn} or task reference id.
	HPMInt32 m_IDData;			// [default=0] Id 2. Can be resource id or id data for column.
	HPMUniqueID m_ContainerID;	// Container id. Can be project id.
} HPMDashboardChartDataIdentifier;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Limit type.																	|
|																									|
|	See Also:			@{HPMDashboardChartLimit}, 													|
|						@{HPMDashboardChartMeasure} and @{HPMDashboardChartForecastingConfig}		|
|						@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartLimitType
{
	EHPMDashboardChartLimitType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartLimitType_Identifiers,				// Limit by identifiers.
	EHPMDashboardChartLimitType_Time,						// Limit by time.
	EHPMDashboardChartLimitType_NumericValue,				// Limit by numeric value.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Time limits																	|
|																									|
|	See Also:			@{HPMDashboardChartLimit}													|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartLimitTime
{
	HPMUInt64 m_Start;	// [default=0] The start time expressed as micro seconds since 1970 UTC.
	HPMUInt64 m_End;	// [default=0] The end time expressed as micro seconds since 1970 UTC.
} HPMDashboardChartLimitTime;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Numerical value limit														|
|																									|
|	See Also:			@{HPMDashboardChartLimit}													|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartLimitNumericValue
{
	HPMInt32 m_NumericValue;	// [default=0] Numverical value limit
} HPMDashboardChartLimitNumericValue;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Data identifier limits														|
|																									|
|	See Also:			@{HPMDashboardChartLimit}													|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartLimitByDataIdentifiers
{
	HPMUInt32 m_nIdentifiers;								// Number of identifiers in m_pIdentifiers
	HPMDashboardChartDataIdentifier const* m_pIdentifiers;	// Indentifier limits
} HPMDashboardChartLimitByDataIdentifiers;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart limits, used to limit or filter the chart configuration.				|
|																									|
|	See Also:			@{HPMDashboardChartForecastingConfig}										|
|						@{HPMDashboardChartDimension}												|
|						@{HPMDashboardChartMeasure}													|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartLimit
{
	HPMUInt32 m_LimitType;												// [type=EHPMDashboardChartLimitType,default=EHPMDashboardChartLimitType_Identifiers] The type for this limit. See @{EHPMDashboardChartLimitType}
	HPMDashboardChartLimitByDataIdentifiers m_LimitByDataIdentifiers;	// Only valid if m_LimitType is set to EHPMDashboardChartLimitType_Identifiers
	HPMDashboardChartLimitTime m_LimitByTime;							// Only valid if m_LimitType is set to EHPMDashboardChartLimitType_Time
	HPMDashboardChartLimitNumericValue m_LimitByNumericValue;			// Only valid if m_LimitType is set to EHPMDashboardChartLimitType_NumericValue
} HPMDashboardChartLimit;



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Sort order, used for @{HPMDashboardChartItemViewConfig}::m_SortDirection.	|
|																									|
|	See Also:			@{HPMDashboardChartItemViewConfig}											|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartSortDirection
{
	EHPMDashboardChartSortDirection_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartSortDirection_Ascending,					// Ascending order
	EHPMDashboardChartSortDirection_Descending,					// Descending order
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart item view configuration,												|
|						used for @{HPMDashboardChartComputationConfig}::m_ItemViewConfig.			|
|																									|
|	See Also:			@{HPMDashboardChartComputationConfig}										|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartItemViewConfig
{
	HPMUInt32 m_nVisibleColumns;				// Number of visible columns
	HPMColumn const* m_pVisibleColumns;			// Visible column list
	HPMColumn m_SortingColumn;					// Sorting column
	HPMUInt32 m_SortDirection;					// [type=EHPMDashboardChartSortDirection,default=EHPMDashboardChartSortDirection_Ascending]. Direction to use for sorting column.
} HPMDashboardChartItemViewConfig;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart filter category, used for @{HPMDashboardChartFilter}::m_Category.		|
|																									|
|	See Also:			@{HPMDashboardChartFilter}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartFilterCategory
{
	EHPMDashboardChartFilterCategory_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartFilterCategory_None,						// No filter category.
	EHPMDashboardChartFilterCategory_Project,					// Project filter.
	EHPMDashboardChartFilterCategory_Report,					// Report filter.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart project type filter													|
|																									|
|	See Also:			@{HPMDashboardChartFilter}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartFilterProjectType
{
	EHPMDashboardChartFilterProjectType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartFilterProjectType_AllItems,					// Filter all project item types.
	EHPMDashboardChartFilterProjectType_Planning,					// Filter planning view items.
	EHPMDashboardChartFilterProjectType_Backlog,					// Filter backlog items.
	EHPMDashboardChartFilterProjectType_QA,							// Filter QA items.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart filter configuration.													|
|																									|
|	See Also:			@{HPMDashboardChartMeasure}													|
|						@{HPMDashboardChartComputationConfig}										|
|						@{DashboardUtilGetFilterAutoName}											|
|						@{DashboardUtilIsFilterValidForResource}									|
|						@{DashboardUtilIsComputationConfigValidForResource}							|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartFilter
{
	HPMUInt32 m_Category;							// [type=EHPMDashboardChartFilterCategory,default=EHPMDashboardChartFilterCategory_None]. Filter category.
	HPMDashboardChartDataIdentifier m_Identifier;	// Data identifier to filter. EHPMDashboardChartFilterCategory_Project: m_ContainerID = ProjectID, m_ID = EHPMDashboardChartFilterProjectType, 
													// EHPMDashboardChartFilterCategory_Report: m_IDData = UserID, m_ContainerID = ProjectID, m_ID = ReportID
	HPMReport m_CompleteReport;						// Only valid for historic configs and when m_Category is set to EHPMDashboardChartFilterCategory_Report
} HPMDashboardChartFilter;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart forecasting date settings,											|
|						used for @{HPMDashboardChartForecastingConfig}::m_DateRange					|
|						in connection with @{HPMDashboardChartForecastingConfig}::m_DateLimit		|
|																									|
|	See Also:			@{HPMDashboardChartForecastingConfig}										|
|						@{HPMDashboardChartLimitTime}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartForcastingDateRange
{
	EHPMDashboardChartForcastingDateRange_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartForcastingDateRange_None,						// No forecasting date set.
	EHPMDashboardChartForcastingDateRange_UntilDate,				// Forecast until set date.
	EHPMDashboardChartForcastingDateRange_UntilNextXDays,			// Forecast next X days.
	EHPMDashboardChartForcastingDateRange_UntilNextXWeeks,			// Forecast next X weeks.
	EHPMDashboardChartForcastingDateRange_UntilNextXMonths,			// Forecast next X monts.
	EHPMDashboardChartForcastingDateRange_UntilNextXQuarters,		// Forecast next X quarters.
	EHPMDashboardChartForcastingDateRange_UntilNextXYears,			// Forecast next X years.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Velocity method to use for forecasting,										|
|						used for @{HPMDashboardChartForecastingConfig}::m_VelocityMethod.			|
|																									|
|	See Also:			@{HPMDashboardChartForecastingConfig}										|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartForcastingVelocityMethod
{
	EHPMDashboardChartForcastingVelocityMethod_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartForcastingVelocityMethod_None,					// No forecasting velocity
	EHPMDashboardChartForcastingVelocityMethod_WeightedAverage,			// Weighted average
	EHPMDashboardChartForcastingVelocityMethod_Custom,					// Custom velocity from m_VelocityValue.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart forecasting configuration,											|
|						used for @{HPMDashboardChartDimension}::m_Forecasting,						|
|						only used for time dimensions.												|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartForecastingConfig
{
	HPMUInt32 m_DateRange;						// [type=EHPMDashboardChartForcastingDateRange,default=EHPMDashboardChartForcastingDateRange_None] The date range for the forecast. Can be one of @{EHPMDashboardChartForcastingDateRange}.
	HPMDashboardChartLimit m_Limit;				// Limits for forecast. Only EHPMDashboardChartLimitType_NumericValue and EHPMDashboardChartLimitType_Time valid here
	HPMUInt32 m_VelocityMethod;					// [type=EHPMDashboardChartForcastingVelocityMethod,default=EHPMDashboardChartForcastingVelocityMethod_WeightedAverage] Velocity for forecast. Can be one of @{EHPMDashboardChartForcastingVelocityMethod}.
	HPMFP32 m_VelocityMethodValue;				// [default=0.0f] The velocity method value. If m_VelocityMethod is @{EHPMDashboardChartForcastingVelocityMethod}_WeightedAverage the value is the number of days, decimals ignored, if it is @{EHPMDashboardChartForcastingVelocityMethod}_Custom it is the true velocity value.
} HPMDashboardChartForecastingConfig;



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart dimension category, 													|
|						used for @{HPMDashboardChartDimension}::m_Category.							|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionCategory
{
	EHPMDashboardChartDimensionCategory_NewVersionOfSDKRequired,		// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartDimensionCategory_None,							// No category
	EHPMDashboardChartDimensionCategory_HistoricalData,					// Historical data
	EHPMDashboardChartDimensionCategory_ProjectColumnData,				// Project column
	EHPMDashboardChartDimensionCategory_PipelinesKanbansAndWorkflows,	// Pipelines, Kanbans and Workflows
	EHPMDashboardChartDimensionCategory_Releases,						// Releases
	EHPMDashboardChartDimensionCategory_Sprints,						// Sprints
	EHPMDashboardChartDimensionCategory_Users,							// Users
	EHPMDashboardChartDimensionCategory_Groups,							// Groups
	EHPMDashboardChartDimensionCategory_Projects,						// Projects
};



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart historical data time range,											|
|						used for @{HPMDashboardChartDimension}::m_TimeRange,						|
|						in connection with @{HPMDashboardChartDimension}::m_Limit					|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|						@{HPMDashboardChartLimit}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionTimeRange
{
	EHPMDashboardChartDimensionTimeRange_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartDimensionTimeRange_None,						// No historical data.
	EHPMDashboardChartDimensionTimeRange_AutomaticFromData,			// Automatic from available data.
	EHPMDashboardChartDimensionTimeRange_DateRange,					// From date range.
	EHPMDashboardChartDimensionTimeRange_LastXDays,					// Last X days.
	EHPMDashboardChartDimensionTimeRange_LastXWeeks,				// Last X weeks.
	EHPMDashboardChartDimensionTimeRange_LastXMonths,				// Last X months.
	EHPMDashboardChartDimensionTimeRange_LastXQuarters,				// Last X quarters.
	EHPMDashboardChartDimensionTimeRange_LastXYears,				// Last X years.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart dimension time resolution,											|
|						used for @{HPMDashboardChartDimension}::m_TimeResolution.					|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionTimeResolution
{
	EHPMDashboardChartDimensionTimeResolution_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartDimensionTimeResolution_Days,						// Time resolution in days.
	EHPMDashboardChartDimensionTimeResolution_Weeks,					// Time resolution in weeks.
	EHPMDashboardChartDimensionTimeResolution_Months,					// Time resolution in months.
	EHPMDashboardChartDimensionTimeResolution_Quarters,					// Time resolution in quarters.
	EHPMDashboardChartDimensionTimeResolution_Years,					// Time resolution in years.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart dimension sort method,												|
|						used for @{HPMDashboardChartDimension}::m_SortMethod.						|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionSortMethod
{
	EHPMDashboardChartDimensionSortMethod_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartDimensionSortMethod_Natural,					// Sort dimension in natural order
	EHPMDashboardChartDimensionSortMethod_Numeric,					// Sort dimension in numeric order
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart dimension sort direction,												|
|						used for @{HPMDashboardChartDimension}::m_SortDirection.					|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionSortDirection
{
	EHPMDashboardChartDimensionSortDirection_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartDimensionSortDirection_Ascending,					// Ascending order
	EHPMDashboardChartDimensionSortDirection_Descending,				// Descending order
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart dimension group expansion												|
|						used for @{HPMDashboardChartDimension}::m_GroupExpansion.					|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionGroupExpansion
{
	EHPMDashboardChartDimensionGroupExpansion_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartDimensionGroupExpansion_Off,						// Do not expand groups
	EHPMDashboardChartDimensionGroupExpansion_On,						// Expand groups to users
};



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart dimension settings enabled,											|
|						used for @{HPMDashboardChartDimension}::m_Enabled.							|
|																									|
|	See Also:			@{HPMDashboardChartDimension}												|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartDimensionSettingEnabled
{
	EHPMDashboardChartDimensionSettingEnabled_None = 0,					// No settings.
	EHPMDashboardChartDimensionSettingEnabled_Category = 1 << 0,		// Category setting.
	EHPMDashboardChartDimensionSettingEnabled_SubCategory = 1 << 1,		// Sub category setting.
	EHPMDashboardChartDimensionSettingEnabled_TimeRange = 1 << 2,		// Time range setting.
	EHPMDashboardChartDimensionSettingEnabled_TimeResolution = 1 << 3,	// Time resolution setting.
	EHPMDashboardChartDimensionSettingEnabled_SortMethod = 1 << 4,		// Sorting method setting.
	EHPMDashboardChartDimensionSettingEnabled_SortDirection = 1 << 5,	// Sorting direction setting.
	EHPMDashboardChartDimensionSettingEnabled_GroupExpansion = 1 << 6,	// Group expansion setting.
	EHPMDashboardChartDimensionSettingEnabled_Limits = 1 << 7,			// Dimension limits setting.
	EHPMDashboardChartDimensionSettingEnabled_Forcasting = 1 << 8,		// Forecasting setting.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart dimension	configuration.												|
|																									|
|	See Also:			@{HPMDashboardChartComputationConfig}										|
|						@{DashboardUtilIsDimensionValidForResource}									|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartDimension
{
	HPMUInt32 m_Enabled;								// [type=EHPMDashboardChartDimensionSettingEnabled,default=EHPMDashboardChartDimensionSettingEnabled_None] Enabled settings, can be any combination of EHPMDashboardChartDimensionSettingEnabled.
	HPMUInt32 m_Category;								// [type=EHPMDashboardChartDimensionCategory,default=EHPMDashboardChartDimensionCategory_None] Dimension category.
	HPMDashboardChartDataIdentifier m_SubCategory;		// Sub category identifier. EHPMDashboardChartDimensionCategory_ProjectColumnData: m_ID = EHPMProjectDefaultColumn, m_IDData = IDData for column, otherwise unused
	HPMUInt32 m_TimeRange;								// [type=EHPMDashboardChartDimensionTimeRange,default=EHPMDashboardChartDimensionTimeRange_None] Time range setting.
	HPMUInt32 m_TimeResolution;							// [type=EHPMDashboardChartDimensionTimeResolution,default=EHPMDashboardChartDimensionTimeResolution_Days] Time resolution setting.
	HPMUInt32 m_SortMethod;								// [type=EHPMDashboardChartDimensionSortMethod,default=EHPMDashboardChartDimensionSortMethod_Natural] Sorting method.
	HPMUInt32 m_SortDirection;							// [type=EHPMDashboardChartDimensionSortDirection,default=EHPMDashboardChartDimensionSortDirection_Ascending] Sorting direction.
	HPMUInt32 m_GroupExpansion;							// [type=EHPMDashboardChartDimensionGroupExpansion,default=EHPMDashboardChartDimensionGroupExpansion_On] Group expansion setting.
	HPMDashboardChartLimit m_Limit;						// Dimension limits setting. Resources, Groups: m_ID = ResourceID, m_IDData = EHPMResourceGroupingType
														// (Pipelines and Workflows), (m_Category = EHPMDashboardChartDimensionCategory_ProjectColumnData, m_SubCategory.m_ID = EHPMProjectDefaultColumn_WorkflowEnterByUser): m_ContainerID = ProjectID, m_ID = WorkflowID, m_IDData = WorkflowStatusID
														// Milestones: m_ID as TaskRefID
														// Projects: m_ID as ProjectID
														// Sprints: m_ID as TaskRefID
	HPMDashboardChartForecastingConfig m_Forecasting;	// Forecasting setting, only used when Category is EHPMDashboardChartDimensionCategory_HistoricalData.
} HPMDashboardChartDimension;



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart measure category,														|
|						used for @{HPMDashboardChartMeasure}::m_Category.							|
|																									|
|	See Also:			@{HPMDashboardChartMeasure}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartMeasureCategory
{
	EHPMDashboardChartMeasureCategory_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartMeasureCategory_None,						// No category.
	EHPMDashboardChartMeasureCategory_ProjectColumnData,		// Project column data.
	EHPMDashboardChartMeasureCategory_Allocation,				// Allocation.
	EHPMDashboardChartMeasureCategory_NumberOfItems,			// Number of items.
	EHPMDashboardChartMeasureCategory_SprintBurndown,			// Sprint burndown.
	EHPMDashboardChartMeasureCategory_ReleaseBurndown,			// Release burndown.
	EHPMDashboardChartMeasureCategory_SprintAllocation,			// Sprint allocation.
	EHPMDashboardChartMeasureCategory_SprintCapacity,			// Release capacity.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart measure aggregation function,											|
|						used for @{HPMDashboardChartMeasure}::m_AggregationFunction.				|
|																									|
|	See Also:			@{HPMDashboardChartMeasure}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartMeasureAggregationFunction
{
	EHPMDashboardChartMeasureAggregationFunction_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartMeasureAggregationFunction_Sum,						// Sum.
	EHPMDashboardChartMeasureAggregationFunction_Average,					// Average value.
	EHPMDashboardChartMeasureAggregationFunction_Min,						// Minimum value.
	EHPMDashboardChartMeasureAggregationFunction_Max,						// Maximum value.
	EHPMDashboardChartMeasureAggregationFunction_First,						// First value.
	EHPMDashboardChartMeasureAggregationFunction_Last,						// Last value.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart measure time range limit,												|
|						used for @{HPMDashboardChartMeasure}::m_TimeRange							|
|						in connection with @{HPMDashboardChartMeasure}::m_Limit						|
|																									|
|	See Also:			@{HPMDashboardChartMeasure}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartMeasureTimeRange
{
	EHPMDashboardChartMeasureTimeRange_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartMeasureTimeRange_None,					// No time range.
	EHPMDashboardChartMeasureTimeRange_DateRange,				// Date range.
	EHPMDashboardChartMeasureTimeRange_LastXDays,				// Last X days.
	EHPMDashboardChartMeasureTimeRange_LastXWeeks,				// Last X weeks.
	EHPMDashboardChartMeasureTimeRange_LastXMonths,				// Last X months.
	EHPMDashboardChartMeasureTimeRange_LastXQuarters,			// Last X quarters.
	EHPMDashboardChartMeasureTimeRange_LastXYears,				// Last X years.
	EHPMDashboardChartMeasureTimeRange_FutureXDays,				// Future X days.
	EHPMDashboardChartMeasureTimeRange_FutureXWeeks,			// Future X weeks.
	EHPMDashboardChartMeasureTimeRange_FutureXMonths,			// Future X months.
	EHPMDashboardChartMeasureTimeRange_FutureXQuarters,			// Future X quarters.
	EHPMDashboardChartMeasureTimeRange_FutureXYears,			// Future X years.
};

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart measure allocation type,												|
|						used for @{HPMDashboardChartMeasure}::m_AllocationType.						|
|																									|
|	See Also:			@{HPMDashboardChartMeasure}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartMeasureAllocationType
{
	EHPMDashboardChartMeasureAllocationType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartMeasureAllocationType_AllocatedTime,				// Allocated time.
	EHPMDashboardChartMeasureAllocationType_Capacity,					// Capacity.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Enum:																							|
|																									|
|	Description:		Chart measure burndown type,												|
|						used for @{HPMDashboardChartMeasure}::m_BurndownType.						|
|																									|
|	See Also:			@{HPMDashboardChartMeasure}													|
|																									|
|	Location:			Enumerations																|
|																									|
|	Index:				!name																		|
|						!enums																		|
\*_________________________________________________________________________________________________*/
enum EHPMDashboardChartMeasureBurndownType
{
	EHPMDashboardChartMeasureBurndownType_NewVersionOfSDKRequired,	// The value did not exist when this SDK was created. Upgrade to a newer version of the SDK to be able to use this type.
	EHPMDashboardChartMeasureBurndownType_None,						// No burndown.
	EHPMDashboardChartMeasureBurndownType_WorkRemaining,			// Work remaining burndown.
	EHPMDashboardChartMeasureBurndownType_Points,					// Points burndown.
	EHPMDashboardChartMeasureBurndownType_IdealDays,				// Ideal days burndown.
};


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart measure configuration													|
|																									|
|	See Also:			@{DashboardUtilGetMeasureAutoName}											|
|						@{DashboardUtilIsMeasureValidForResource}									|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartMeasure
{
	HPMUInt32 m_Category;									// [type=EHPMDashboardChartMeasureCategory,default=EHPMDashboardChartMeasureCategory_None]. Measure category.
	const HPMChar *m_pCustomName;							// Measure custom name

	HPMUInt32 m_TimeRange;									// [type=EHPMDashboardChartMeasureTimeRange,default=EHPMDashboardChartMeasureTimeRange_None] Time range.
	HPMDashboardChartLimit m_Limit;							// Measure limits. Only EHPMDashboardChartLimitType_NumericValue and EHPMDashboardChartLimitType_Time valid here
	HPMUInt32 m_AllocationType;								// [type=EHPMDashboardChartMeasureAllocationType,default=EHPMDashboardChartMeasureAllocationType_AllocatedTime] Allocation type.
	HPMUInt32 m_nIdentifiers;								// Number of identifiers.
	HPMDashboardChartDataIdentifier const* m_pIdentifiers;	// List of identifiers. If m_Category is EHPMDashboardChartMeasureCategory_ReleaseBurndown: The task refs of the releases to measure in m_ID
															// EHPMDashboardChartMeasureCategory_SprintBurndown: The task refs of the sprints to measure in m_ID
															// EHPMDashboardChartMeasureCategory_ProjectColumnData: Only one ident: m_ID = EHPMProjectDefaultColumn, m_IDData = Column IDData
	HPMDashboardChartFilter m_Filter;						// Measure filter.

	HPMUInt32 m_BurndownType;								// [type=EHPMDashboardChartMeasureBurndownType,default=EHPMDashboardChartMeasureBurndownType_None]. Measure burndown type.
	
	HPMUInt32 m_AggregationFunction;						// [type=EHPMDashboardChartMeasureAggregationFunction,default=EHPMDashboardChartMeasureAggregationFunction_Sum]. Measure aggregation function.
	
	HPMFP64	m_ScaleByFinalValue;							// [default=1.0]. Measure scale value.
	HPMInt32 m_bScaleByAllocation;							// [default=0]. Scale measure by allocation.
	
} HPMDashboardChartMeasure;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart computation configuration												|
|																									|
|	See Also:			@{DashboardChartCreate}														|
|						@{DashboardChartGetComputationConfig}										|
|						@{DashboardChartSetComputationConfig}										|
|						@{DashboardChartGetLastSampledHistoricComputationConfig}					|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartComputationConfig
{
	HPMUniqueID m_ChartOwner;							// Chart owner.
	
	HPMUInt32 m_nFilters;								// Number of filters.
	HPMDashboardChartFilter const* m_pFilters;			// List of filters.
	
	HPMUInt32 m_nDimensions;							// Number of dimensions.
	HPMDashboardChartDimension const* m_pDimensions;	// List of dimensions.

	HPMUInt32 m_nMeasures;								// Number of measures.
	HPMDashboardChartMeasure const* m_pMeasures;		// List of measures.
	
	HPMDashboardChartItemViewConfig m_ItemViewConfig;	// Item view configuration.

	HPMInt32 m_bSupressZeroValues;						// Suppression of zero values.

	HPMUInt64 m_ShowHistoricalDataFromDate;				// [default=0] The start time for showing historical data. Only valid if there is a time dimension. Expressed as micro seconds since 1970 UTC.
	HPMUInt64 m_EarliestSampledTime;					// [default=0] The time when this configuration was first sampled. Only valid when getting historic data. Expressed as micro seconds since 1970 UTC.
	
	HPMUInt32 m_OriginalVersion;						// Original version number when chart configuration was created, used for backwards compatibility.
} HPMDashboardChartComputationConfig;


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart historic computation configuration list.								|
|																									|
|	See Also:			@{DashboardChartGetHistoricComputationConfigs}								|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartHistoricComputationConfigs
{
	HPMUInt32 m_nConfigurations;									// Number of configurations.
	HPMDashboardChartComputationConfig const* m_pConfigurations;	// List of configurations.
} HPMDashboardChartHistoricComputationConfigs;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Chart validation result														|
|																									|
|	See Also:			@{DashboardUtilIsComputationConfigValidForResource}							|
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardChartValidationResult
{
	HPMInt32 m_bValid;				// [type=bool,default=0]. True if chart is valid.
	HPMUntranslatedString const* m_pError;	// List of errors.
} HPMDashboardChartValidationResult;

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Class:																							|
|																									|
|	Description:		Dashboard themes.															|
|																									|
|	See Also:			@{DashboardThemeEnum}														|						
|																									|
|	Location:			Structures																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/
typedef struct HPMDashboardThemes
{
	HPMUInt32 m_nThemes;			// Number of themes.
	HPMString const* m_pThemes;		// List of themes.
} HPMDashboardThemes;



#ifndef DHPMSdk_OnlyDefinitions

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Enumerates dashboard page IDs in a database.								|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMUniqueEnum}							|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageEnum															|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageEnum)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																			HPMUniqueEnum const **_pEnum	// [out] Pointer to a pointer of a @{HPMUniqueEnum} object, representing the returned dashboard page IDs.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Returns the name for a page.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageGetName														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageGetName)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,			// [in] The unique identifier of the page to get the name for.
																				HPMString const **_pData		// [out] Pointer to a pointer of a @{HPMString} object holding the name of the page.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Sets the name for a page.													|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageSetName														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageSetName)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,			// [in] The unique identifier of the page to set the name for.
																				HPMChar const *_pNewPageName	// [in] New page name to set on the page.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Returns the theme for a page.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageGetTheme														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageGetTheme)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,			// [in] The unique identifier of the page to get the theme for.
																				HPMString const **_pData		// [out] Pointer to a pointer of a @{HPMString} object holding the theme of the page.
																			);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Sets the theme for a page.													|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageSetTheme														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageSetTheme)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,			// [in] The unique identifier of the page to set the theme for.
																				HPMChar const *_pNewPageTheme	// [in] New page theme to set on the page.
																			);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Returns all available themes.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardThemeEnum															|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardThemeEnum)(	void *_pSession,						// [in] A connected session. See @{SessionOpen}.
																			HPMDashboardThemes const **_pData		// [out] Pointer to a pointer of a @{HPMDashboardThemes} object holding the available themes.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Gets the list of resources that a page is shared to (with viewing rights)	|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageGetSharedToWithViewingRights									|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageGetSharedToWithViewingRights)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																									HPMUniqueID _PageID, 							// [in] The unique identifier of the page to get the list of resources that the page is shared to (with viewing rights).
																									HPMResourceDefinitionList const **_pResult		// [out] The resources. See @{HPMResourceDefinitionList}.
																					);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Sets the list of resources that a page is shared to (with viewing rights)	|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageSetSharedToWithViewingRights									|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageSetSharedToWithViewingRights)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																									HPMUniqueID _PageID, 							// [in] The unique identifier of the page to set the list of resources that the page is shared to (with viewing rights).
																									HPMResourceDefinitionList const *_pResourceList	// [in] The resources. See @{HPMResourceDefinitionList}.
																					);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Gets the list of resources that a page is shared to (with editing rights)	|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageGetSharedToWithEditingRights									|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageGetSharedToWithEditingRights)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																									HPMUniqueID _PageID, 							// [in] The unique identifier of the page to get the list of resources that the page is shared to (with editing rights).
																									HPMResourceDefinitionList const **_pResult		// [out] The resources. See @{HPMResourceDefinitionList}.
																					);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Sets the list of resources that a page is shared to (with editing rights)	|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageSetSharedToWithEditingRights									|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageSetSharedToWithEditingRights)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																									HPMUniqueID _PageID, 							// [in] The unique identifier of the page to set the list of resources that the page is shared to (with editing rights).
																									HPMResourceDefinitionList const *_pResourceList	// [in] The resources. See @{HPMResourceDefinitionList}.
																					);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Deletes the page with the given unique identifier.							|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageDelete															|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageDelete)(	void *_pSession,		// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID		// [in] The unique identifier of the page to delete.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Creates a new dashboards page.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Managed:			CanBlock																	|
|																									|
|	Index:				!name																		|
|						DashboardPageCreate															|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageCreate)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																				HPMChar const* _pPageName,		// [in] The name of the page to create.
																				HPMUniqueID _LocalObjectID,		// [in] Optional supplied local id that will be returned when page is created.
																				HPMUniqueID *_pReturnedPageID	// [out] The unique identifier of the created page. This function will block even in non-blocking mode if this parameter is not NULL.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Returns whether the dashboard page is a personal resource page				|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageIsPersonal														|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageIsPersonal)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																					HPMUniqueID _PageID,			// [in] The unique identifier of the page to check.
																					HPMInt32 *_pReturn				// [out,type=bool] Set to 1 if the dashboard page is personal to a resource, 0 otherwise
																		);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Returns the unique identifier of the resource that created the page			|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageGetCreatedBy													|
\*_________________________________________________________________________________________________*/
typedef HPMError (DHPMSdkCallingConvention *HPMFunctionDashboardPageGetCreatedBy)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																					HPMUniqueID _PageID,			// [in] The unique identifier of the page to get the creator for.
																					HPMUniqueID *_pReturn			// [out] The unique identifier of the resource that created the page.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Returns the layout for a page.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardPageLayout}				|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageGetLayout														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageGetLayout)(	void *_pSession,						// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,					// [in] The unique identifier of the page to get the layout for.
																				HPMDashboardPageLayout const **_pData	// [out] Pointer to a pointer of a @{HPMDashboardPageLayout} object holding the layout of the page.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Sets the layout for a page.													|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardPageLayout}				|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardPageSetLayout														|
|																									|
|	Managed:			ExtendedError																|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardPageSetLayout)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,							// [in] The unique identifier of the page to set the layout for.
																				HPMDashboardPageLayout const *_pNewPageTheme	// [in] New page layout to set on the page.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Enumerates chart IDs on a dashboard page.									|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMUniqueEnum}							|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartEnum															|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartEnum)(	void *_pSession,				// [in] A connected session. See @{SessionOpen}.
																			HPMUniqueID _PageID,			// [in] The unique identifier of the page to get the charts for.
																			HPMUniqueEnum const **_pEnum	// [out] Pointer to a pointer of a @{HPMUniqueEnum} object, representing the returned dashboard chart IDs.
																		);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Create chart on dashboard page.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{HPMDashboardChartPresentationConfig}					|
|						@{HPMDashboardChartComputationConfig}										|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartCreate														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartCreate)(	void *_pSession,													// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _PageID,												// [in] The unique identifier of the page to create the chart on.
																				const HPMDashboardChartPresentationConfig *_pPresentationConfig,	// [in] Presentation configuration.
																				const HPMDashboardChartComputationConfig *_pComputationConfig,		// [in] Computation configuration.
																				HPMUniqueID _LocalObjectID,											// [in] Local ID.
																				HPMUniqueID _CloneFromChartID,										// [in] Optional source chart ID for cloning. The presentation and computation configurations will not be cloned automatically.
																				HPMUniqueID * _pReturnedChartID										// [out] ID of created chart.
																			);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Delete chart.																|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartDelete														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartDelete)(	void *_pSession,		// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _ChartID	// [in] The unique identifier of the chart to delete.
																			);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Set chart name.																|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}															|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartSetName														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartSetName)(	void *_pSession,		// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _ChartID,	// [in] The unique identifier of the chart to set the name for.
																				const HPMChar *_pName	// [in] New name.
																				);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Set chart presentation configuration.										|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{HPMDashboardChartPresentationConfig}					|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartSetPresentationConfig											|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartSetPresentationConfig)(	void *_pSession,									// [in] A connected session. See @{SessionOpen}.
																							HPMUniqueID _ChartID,								// [in] The unique identifier of the chart to set the presentation config for.
																							const HPMDashboardChartPresentationConfig *_pConfig	// [in] New presentation configuration.
																						);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Set chart computation configuration.										|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{HPMDashboardChartComputationConfig}					|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartSetComputationConfig											|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartSetComputationConfig)(	void *_pSession,									// [in] A connected session. See @{SessionOpen}.
																							HPMUniqueID _ChartID,								// [in] The unique identifier of the chart to set the computation config for.
																							const HPMDashboardChartComputationConfig *_pConfig	// [in] New chart computation configuration.
																						);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get chart name.																|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartGetName														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartGetName)(	void *_pSession,			// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _ChartID,		// [in] Chart ID.
																				HPMString const **_pData	// [out] Chart name.
																			  );


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get chart dashboard page ID.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartGetPageID														|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartGetPageID)(	void *_pSession,		// [in] A connected session. See @{SessionOpen}.
																				HPMUniqueID _ChartID,	// [in] Chart ID.
																				HPMUniqueID *_pPageID	// [out] Dashboard page ID.
																			  );


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get chart computation configuration.										|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartComputationConfig}	|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartGetComputationConfig											|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartGetComputationConfig)(	void *_pSession,									// [in] A connected session. See @{SessionOpen}.
																							HPMUniqueID _ChartID,								// [in] Chart ID.
																							HPMDashboardChartComputationConfig const **_pData	// [out] Computation configuration.
																						  );


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get chart presentation configuration.										|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartPresentationConfig}	|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartGetPresentationConfig											|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartGetPresentationConfig)(	void *_pSession,									// [in] A connected session. See @{SessionOpen}.
																								HPMUniqueID _ChartID,								// [in] Chart ID.
																								HPMDashboardChartPresentationConfig const **_pData	// [out] Presentation configuration.
																							);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get chart historic computation configurations.								|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree},											|
|						@{HPMDashboardChartHistoricComputationConfigs}								|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartGetHistoricComputationConfigs									|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartGetHistoricComputationConfigs)(	void *_pSession,											// [in] A connected session. See @{SessionOpen}.
																									HPMUniqueID _ChartID,										// [in] Chart ID.
																									HPMDashboardChartHistoricComputationConfigs const **_pData	// [out] Computation configurations.
																								);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get chart last sampled historic computation configuration.					|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartComputationConfig}	|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardChartGetLastSampledHistoricComputationConfig						|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardChartGetLastSampledHistoricComputationConfig)(	void *_pSession,									// [in] A connected session. See @{SessionOpen}.
																												HPMUniqueID _ChartID,								// [in] Chart ID.
																												HPMDashboardChartComputationConfig const **_pData	// [out] Computation configuration.
																											);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get automatic name for measure.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartMeasure}				|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilGetMeasureAutoName												|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilGetMeasureAutoName)(	void *_pSession,							// [in] A connected session. See @{SessionOpen}.
																						HPMDashboardChartMeasure const *_pMeasure,	// [in] Measure configuration.
																						HPMUntranslatedString const **_pData		// [out] Measure automatic name.
																						);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Get automatic name for filter.												|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartFilter}				|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilGetFilterAutoName												|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilGetFilterAutoName)(	void *_pSession,							// [in] A connected session. See @{SessionOpen}.
																						HPMDashboardChartFilter const *_pFilter,	// [in] Filter configuration.
																						HPMUntranslatedString const **_pData		// [out] Filter automatic name.
																						);



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Check if column can be used as a dimension.									|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}											|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilColumnCanBeUsedForDimension									|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilColumnCanBeUsedForDimension)(	void *_pSession,			// [in] A connected session. See @{SessionOpen}.
																									HPMColumn const *_pColumn,	// [in] Column.
																									HPMInt32 *_pData			// [out,type=bool] True if column can be used as dimension.
																								);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Check if dimension is valid for resource.									|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartDimension}			|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilIsDimensionValidForResource									|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilIsDimensionValidForResource)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																									HPMDashboardChartDimension const *_pDimension,	// [in] Dimension configuration.
																									HPMUniqueID _ForResourceID,						// [in] Resource ID.
																									HPMInt32 *_pData								// [out,type=bool] True if dimension is valid for resource.
																								);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Check if measure is valid for resource.										|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartMeasure}				|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilIsMeasureValidForResource										|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilIsMeasureValidForResource)(	void *_pSession,							// [in] A connected session. See @{SessionOpen}.
																								HPMDashboardChartMeasure const *_pMeasure,	// [in] Measure configuration.
																								HPMUniqueID _ForResourceID,					// [in] Resource ID.
																								HPMInt32 *_pData							// [out,type=bool] True if measure is valid for resource.
																								);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Check if filter is valid for resource.										|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartFilter}				|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilIsFilterValidForResource										|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilIsFilterValidForResource)(	void *_pSession,							// [in] A connected session. See @{SessionOpen}.
																								HPMDashboardChartFilter const *_pFilter,	// [in] Filter configuration.
																								HPMUniqueID _ForResourceID,					// [in] Resource ID.
																								HPMInt32 *_pData							// [out,type=bool] True if filter is valid for resource.
																								);


/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Check if computation configuration is valid for resource.					|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree},											|
|						@{HPMDashboardChartFilter}, @{HPMDashboardChartValidationResult}			|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardUtilIsComputationConfigValidForResource							|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardUtilIsComputationConfigValidForResource)(	void *_pSession,									// [in] A connected session. See @{SessionOpen}.
																											HPMDashboardChartComputationConfig const *_pConfig,			// [in] Computation configuration.
																											HPMUniqueID _ForResourceID,							// [in] Resource ID.
																											HPMDashboardChartValidationResult const **_pData	// [out] Validation result.
																										);



/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Subscribes to a chart. Chart data will is received asynchronously and		|
|						a @{EHPMChangeCallbackOperation}_DashboardChartReceived callback signals	|
|						that new data is available.													|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartSubscription}			|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardSubscribeToChart													|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardSubscribeToChart)(	void *_pSession,								// [in] A connected session. See @{SessionOpen}.
																					HPMUniqueID _ChartID,							// [in] The unique identifier of the chart to subscribe to.
																					HPMDashboardChartSubscription const **_pEnum	// [out] Pointer to a pointer of a @{HPMDashboardChartSubscription} object holding the subscription.
																				);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Decodes the latest received result set as string. The result set is			|
|						available when a @{EHPMChangeCallbackOperation}_DashboardChartReceived 		|
|						callback signal is received. If no data has been been received for the 		|
|						subscription, @{EHPMError}_DataNotYetAvailable will be returned.			|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartSubscription}			|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardSubscriptionGetLastResultSetAsString								|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardSubscriptionGetLastResultSetAsString)(	void *_pSession,										// [in] A connected session. See @{SessionOpen}.
																										HPMDashboardChartSubscription const *_pSubscription,	// [in] The chart subscription holding the result set.
																										HPMString const **_pData								// [out] Pointer to a pointer of a @{HPMString} object holding the chart result set as a string.
																									);

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Function:																						|
|																									|
|	Description:		Decodes the latest received result set as a @{HPMDashboardChartResultSet}.	|
|						The result set is available when a  										|
|						@{EHPMChangeCallbackOperation}_DashboardChartReceived callback signal is	|
|						received. If no data has been been received for the subscription, 			|
|						@{EHPMError}_DataNotYetAvailable will be returned.							|
|																									|
|	Return Value:		Returns an error code. See @{EHPMError}.									|
|																									|
|	Comments:			The returned object must be freed with @{ObjectFree} or a memory			|
|						leak will result.															|
|																									|
|	See Also:			@{HPMSdkFunctions}, @{ObjectFree}, @{HPMDashboardChartSubscription}			|
|																									|
|	Location:			Function Pointers															|
|																									|
|	Index:				!name																		|
|						DashboardSubscriptionGetLastResultSet										|
\*_________________________________________________________________________________________________*/
typedef HPMError(DHPMSdkCallingConvention *HPMFunctionDashboardSubscriptionGetLastResultSet)(	void *_pSession,										// [in] A connected session. See @{SessionOpen}.
																								HPMDashboardChartSubscription const *_pSubscription,	// [in] The chart subscription holding the result set.
																								HPMDashboardChartResultSet const **_pData				// [out] Pointer to a pointer of a @{HPMDashboardChartResultSet} object holding the chart result set structure.
																							);

#endif

