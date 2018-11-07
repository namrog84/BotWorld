#pragma once

//Take A Shot 
//Considerations
//	* Execution History(Timer)
//	* Picker(Select Target)
//	* Picker(Line of Retreat)
//	* Integer Variable(Number of Shots) 
//Actions
//	* Write Blackboard(#Shots Fired)
//	* Fire at Target
//
// Note for the pickers
//
//<Option Type="ConsiderationAndAction" Comment="Take A Shot">
//	<Considerations>
//		<Consideration Type="ExecutionHistory">
//			<StoppedWeightFunction Type="FloatSequence">
//				<Entries>
//					<Entry Min="60" Max="120" Veto="true"/>
//				</Entries>
//				<Default Veto="false"/>
//			</StoppedWeightFunction>
//		</Consideration>
//		<Consideration Type="Global" Name="PickTarget"/>
//		<Consideration Type="Global" Name="CheckRetreat"/>
//		<Consideration Type="IntegerVariable" Variable="NumShots">
//			<WeightFunction Type="BasicCurve"> ... </WeightFunction>
//	</Consideration>
//	</Considerations>
//	<Actions>
//		<Action Type="UpdateIntegerVariable" Variable="NumShots"
//			UpdateType="Increment"/>
//		<Action Type="Global" Name="FireAtTarget">
//	</Actions>
//</Option>
//











<Option Type="ConsiderationAndAction">
	<Considerations>
		<!-- Look through the contacts, pick a target, store it on the brain's blackboard as SnipeTarget. -->
		<Consideration Type="EntityExists" Location="Contacts" Variable="SnipeTarget">
			<Picker>
				<!-- This picker uses a dual utility reasoner because it wants to pick the *best* target. A picker
				that just wants to check whether any entity meets some set of constraints (like the one for
				checking line of retreat) would likely use a rule-based reasoner instead. -->
				<Reasoner Type="DualUtility"/>
				<Considerations>
					<!-- Only targets between 50m and 300m away -->
					<Consideration Type="Distance">
						<FromTarget Type="Self"/>
						<ToTarget Type="PickerEntity"/>
						<WeightFunction Type="FloatSequence">
							<Entries>
								<Entry Exact="50" Veto="true"/>
								<Entry Exact="300" Veto="false"/>
							</Entries>
							<Default Veto="true"/>
						</WeightFunction>
					</Consideration>
					<!-- Only enemies -->
					<Consideration Type="StringVariable" Variable="Side" DataStore="Target">
						<DataStoreTarget Type="PickerEntity"/>
						<WeightFunction Type="String">
							<Entries>
								<String Value="Enemy" Veto="False"/>
							</Entries>
							<Default Veto="True"/>
						</WeightFunction>
					</Consideration>
					<!-- Other considerations (like the one to prefer officers, or one to check that the target is in the kill zone) could be added here. -->
				</Considerations>
			</Picker>
			<!-- Use a default Boolean weight function – that is, veto if a target is not found -->
			<WeightFunction Type="Boolean"/>
		</Consideration>
		<!-- The considerations to check line of retreat and time since the last shot would go here. -->
		…
	</Considerations>
	<Actions>
		<!-- Fire at the target the picker picked -->
		<Action Type="Fire">
			<Target Type="DataElement_EntityList" Variable="SnipeTarget"/>
		</Action>
	</Actions>
</Option>