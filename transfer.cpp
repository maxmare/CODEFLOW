:: @action_keyboard_get
; :: @action_keyboard_get
	:: gather all active #input_units in an array,
	:: is at least 1 input_unit active?
		:: compare with the array in the previous frame and ignore shared entries
		:: are there new active input/s?
			:: update the previous input array with the current one.
			:: add the input/s to a current binding query,
			:: query the current input context for actions binded to the query,
			:: is an action found?
				:: this action is to be returned at the end,
				:: reset all previous active inputs to empty,
	:: else,
		:: is this currentContext amodal?
			:: then reset all previous active inputs to empty,
	:: return action. 
	:: return by reference, current binding query & previous input array.

